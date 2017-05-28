#ifndef _TILE_SEQUENCE_H_
#define _TILE_SEQUENCE_H_

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

namespace bejeweled {
	/************************************************************************/
	/* Mo ta cac chuoi cung mau.
	Cac chuoi nay co dong bat dau, cot bat dau, huong(ngang hoac doc), kich thuoc cua 1 chuoi
	*/
	/************************************************************************/
	class TileSequence
	{
	public:
		enum Orientation {
			HORIZONAL,
			VERTICAL
		};

		TileSequence(void);

		TileSequence(int typeId, Orientation orientation, int startRow, int startCol, int size);

		/// Ham tao sao chep
		TileSequence(const TileSequence&);

		/// Khai bao operator 
		TileSequence& operator = (const TileSequence &);

		virtual ~TileSequence(void);

	public:
		/// get kieu Id
		int getTypeId() const;

		/// Get kich thuoc
		int getSize() const;
		
		/// return start row
		int getStartRow() const;

		// return start column
		int getStartCol() const;

		/// Return huong
		Orientation getOrientation() const;

	private:
		/// huong cua day
		Orientation m_orientation;

		/// Kieu cua day
		int m_typeId;

		/// Kich thuoc cua day
		int m_size;

		/// vi tri bat dau cua day
		int m_row;
		int m_col;
 	};
}


#endif
