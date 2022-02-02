﻿
/* ---------------------------------------------------------------  /

	 ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \====================== Game Engine ======,
   `^^^^^^^^^^^^^^^^^^^ /----------------- © 2012 - Ryan Appel -"
					  \/
/  --------------------------------------------------------------- */

#pragma once

namespace KatanaEngine
{
	/** @brief Defines a rectangular region defined by a point, height, width. */
	class Region
	{

	public:

		/** @brief Instantiates a region. */
		Region() : Region(0, 0, 0, 0) { }


		/** @brief Instantiates a region.
			@param position the upper left corner of the region.
			@param size The dimensions of the region.
			
			@overload */
		Region(const Point &position, const Point &size)
			: Region(position, size.X, size.Y) { }

		/** @brief Instantiates a new Region object.
			@param position An array which will be used to initialize the position.
			@param size An array which will be used to initialize the size.

			@overload */
		Region(const int position[2], const int size[2])
			: Region(position[0], position[1], size[0], size[1]) { }

		/** @brief Instantiates a new Region object.
			@param array An array which first pair of elements will be used to
			initialize the position, and the second pair to initialize the size.

			@overload */
		Region(const int array[4])
			: Region(array[0], array[1], array[2], array[3]) { }

		/** @brief Instantiates a new Region object.
			@param position the upper left corner of the region.

			@overload */
		Region(const Point &position, const int width, const int height)
			: Region(position.X, position.Y, width, height) { }

		/** @brief Instantiates a new Region object.
			@param x The left side of the region.
			@param y The top side of the region.
			@param width The width of the region.
			@param height The height of the region.

			@overload */
		Region(const int x, const int y, const int width, const int height)
		{
			Set(x, y, width, height);
		}

		virtual ~Region() { }

		/** @brief Sets the components of the region.
			@param x The left side of the region.
			@param y The top side of the region.
			@param width The width of the region.
			@param height The height of the region.

			@overload */
		void Set(const int x, const int y, const int width, const int height)
		{
			X = x;
			Y = y;
			Width = width;
			Height = height;
		}

		// todo: comments
		void Set(const int array[4])
		{
			Set(array[0], array[1], array[2], array[3]);
		}

		void Set(const int position[2], const int size[2])
		{
			Set(position[0], position[1], size[0], size[1]);
		}

		/** @brief The top of the region.
			@return Returns the top. */
		int GetTop() { return Y; }

		/** @brief The bottom of the region.
			@return Returns the bottom. */
		int GetBottom() { return Y + Height; }

		/** @brief The left side of the region.
			@return Returns the left side. */
		int GetLeft() { return X; }

		/** @brief The right side of the region.
			@return Returns the right side. */
		int GetRight() { return X + Width; }


		/** @brief The top left corner of the region.
			@return Returns the top left corner. */
		Point GetTopLeft() { return Point(GetLeft(), GetTop()); }

		/** @brief The top right corner of the region.
			@return Returns the top right corner. */
		Point GetTopRight() { return Point(GetRight(), GetTop()); }

		/** @brief The bottom left corner of the region.
			@return Returns the bottom left corner. */
		Point GetBottomLeft() { return Point(GetLeft(), GetBottom()); }

		/** @brief The bottom right corner of the region.
			@return Returns the bottom right corner. */
		Point GetBottomRight() { return Point(GetRight(), GetBottom()); }

		/** @brief The center position of the region.
			@return Returns the center position. */
		Vector2 GetCenter() { return GetTopLeft().ToVector2() + (Vector2(Width, Height) / 2); }

		/** @brief Moves the region by the specified amount.
			@param x The amount to move the region on the x-axis. 
			@param y The amount to move the region on the y-axis. */
		void Translate(const int x, const int y)
		{
			X += x;
			Y += y;
		}

		/** @brief Moves the region by the specified amount.
			@param point The amount to move the region.

			@overload */
		void Translate(const Point &point)
		{
			X += point.X;
			Y += point.Y;
		}


		int X = 0;		/**< @brief The left side of the region. */
		int Y = 0;		/**< @brief The top of the region. */
		int Width = 0;	/**< @brief The width of the region. */
		int Height = 0;	/**< @brief The height of the region. */
	};
}