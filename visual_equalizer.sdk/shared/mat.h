#ifndef MAT_H_
#define MAT_H_

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <algorithm>

namespace la
{
	template <typename TYPE_,int SIZE_>
	class pixel
	{
	public:
		pixel() { }
		pixel( TYPE_ val0 )
		{
			data[ 0 ] = val0;
		}
		pixel( TYPE_ val0, TYPE_ val1 )
		{
			data[ 0 ] = val0; data[ 1 ] = val1;
		}
		pixel( TYPE_ val0, TYPE_ val1, TYPE_ val2 )
		{
			data[ 0 ] = val0; data[ 1 ] = val1; data[ 2 ] = val2;
		}
		pixel( TYPE_ val0, TYPE_ val1, TYPE_ val2, TYPE_ val3 )
		{
			data[ 0 ] = val0; data[ 1 ] = val1; data[ 2 ] = val2; data[ 3 ] = val3;
		}
		pixel( const TYPE_* data )
		{
			for ( int each_ch=0; each_ch<SIZE_; each_ch++ )
				this->data[ each_ch ] = data[ each_ch ];
		}
		const pixel& operator=( const pixel& ref )
		{
			std::copy( ref.data, ref.data+SIZE_, data );
			return ref;
		}
		pixel( const pixel& ref ) { *this = ref; }
		~pixel() { }
		TYPE_* get() { data; }
		volatile TYPE_* get() volatile { return static_cast<volatile TYPE_*>( data ); }
	private:
		TYPE_ data[ SIZE_ ];
	};

	template <typename TYPE_,int ROWS_,int COLS_,int STRIDE_>
	class mat
	{
	public:
		mat() { }
		~mat() { }
		TYPE_* get( int row ) {	return reinterpret_cast<TYPE_*>(data+STRIDE_*row); }
		TYPE_& get( int row, int col ) { return *(get( row )+col); }
	private:
		uint8_t data[ STRIDE_*ROWS_ ];
	};

	template <typename TYPE_,int ROWS_,int COLS_,int STRIDE_>
	void fill( mat<TYPE_,ROWS_,COLS_,STRIDE_>& mat, TYPE_& pixel,
			int row = 0, int col = 0,
			int height = ROWS_, int width = COLS_ )
	{
		for ( int row_=row; row_<(row+height); row_++ )
		{
			TYPE_* rowptr = mat.get( row_ );
			std::fill( rowptr+col, rowptr+col+width, pixel );
		}
	}
};

#endif
