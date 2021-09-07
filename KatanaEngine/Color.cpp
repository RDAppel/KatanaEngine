﻿
/*	 ██╗  ██╗  █████╗  ████████╗  █████╗  ███╗   ██╗  █████╗ 
	 ██║ ██╔╝ ██╔══██╗ ╚══██╔══╝ ██╔══██╗ ████╗  ██║ ██╔══██╗
	 █████╔╝  ███████║    ██║    ███████║ ██╔██╗ ██║ ███████║
	 ██╔═██╗  ██╔══██║    ██║    ██╔══██║ ██║╚██╗██║ ██╔══██║
	 ██║  ██╗ ██║  ██║    ██║    ██║  ██║ ██║ ╚████║ ██║  ██║
	 ╚═╝  ╚═╝ ╚═╝  ╚═╝/\  ╚═╝    ╚═╝  ╚═╝ ╚═╝  ╚═══╝ ╚═╝  ╚═╝
   /vvvvvvvvvvvvvvvvvvv \=========================================,
   `^^^^^^^^^^^^^^^^^^^ /---------------------------------------"
        Katana Engine \/ © 2012 - Shuriken Studios LLC              */

#include "KatanaEngine.h"

namespace KatanaEngine
{
#pragma region Static Color Definitions
	const Color Color::ALICE_BLUE = Color(0.94f, 0.97f, 1.0f);
	const Color Color::ANTIQUE_WHITE = Color(0.98f, 0.92f, 0.84f);
	const Color Color::AQUA = Color(0.0f, 1.0f, 1.0f);
	const Color Color::AQUAMARINE = Color(0.5f, 1.0f, 0.83f);
	const Color Color::AZURE = Color(0.94f, 1.0f, 1.0f);
	const Color Color::BEIGE = Color(0.96f, 0.96f, 0.86f);
	const Color Color::BISQUE = Color(1.0f, 0.89f, 0.77f);
	const Color Color::BLACK = Color(0.0f, 0.0f, 0.0f);
	const Color Color::BLANCHED_ALMOND = Color(1.0f, 0.92f, 0.8f);
	const Color Color::BLUE = Color(0.0f, 0.0f, 1.0f);
	const Color Color::BLUE_VIOLET = Color(0.54f, 0.17f, 0.89f);
	const Color Color::BROWN = Color(0.65f, 0.16f, 0.16f);
	const Color Color::BURLYWOOD = Color(0.87f, 0.72f, 0.53f);
	const Color Color::CADET_BLUE = Color(0.37f, 0.62f, 0.63f);
	const Color Color::CHARTREUSE = Color(0.5f, 1.0f, 0.0f);
	const Color Color::CHOCOLATE = Color(0.82f, 0.41f, 0.12f);
	const Color Color::CORAL = Color(1.0f, 0.5f, 0.31f);
	const Color Color::CORNFLOWER = Color(0.39f, 0.58f, 0.93f);
	const Color Color::CORNSILK = Color(1.0f, 0.97f, 0.86f);
	const Color Color::CRIMSON = Color(0.86f, 0.08f, 0.24f);
	const Color Color::CYAN = Color(0.0f, 1.0f, 1.0f);
	const Color Color::DARK_BLUE = Color(0.0f, 0.0f, 0.55f);
	const Color Color::DARK_CYAN = Color(0.0f, 0.55f, 0.55f);
	const Color Color::DARK_GOLDENROD = Color(0.72f, 0.53f, 0.04f);
	const Color Color::DARK_GRAY = Color(0.66f, 0.66f, 0.66f);
	const Color Color::DARK_GREEN = Color(0.0f, 0.39f, 0.0f);
	const Color Color::DARK_KHAKI = Color(0.74f, 0.72f, 0.42f);
	const Color Color::DARK_MAGENTA = Color(0.55f, 0.0f, 0.55f);
	const Color Color::DARK_OLIVE_GREEN = Color(0.33f, 0.42f, 0.18f);
	const Color Color::DARK_ORANGE = Color(1.0f, 0.55f, 0.0f);
	const Color Color::DARK_ORCHID = Color(0.6f, 0.2f, 0.8f);
	const Color Color::DARK_RED = Color(0.55f, 0.0f, 0.0f);
	const Color Color::DARK_SALMON = Color(0.91f, 0.59f, 0.48f);
	const Color Color::DARK_SEA_GREEN = Color(0.56f, 0.74f, 0.56f);
	const Color Color::DARK_SLATE_BLUE = Color(0.28f, 0.24f, 0.55f);
	const Color Color::DARK_SLATE_GRAY = Color(0.18f, 0.31f, 0.31f);
	const Color Color::DARK_TURQUOISE = Color(0.0f, 0.81f, 0.82f);
	const Color Color::DARK_VIOLET = Color(0.58f, 0.0f, 0.83f);
	const Color Color::DEEP_PINK = Color(1.0f, 0.08f, 0.58f);
	const Color Color::DEEP_SKY_BLUE = Color(0.0f, 0.75f, 1.0f);
	const Color Color::DIM_GRAY = Color(0.41f, 0.41f, 0.41f);
	const Color Color::DODGER_BLUE = Color(0.12f, 0.56f, 1.0f);
	const Color Color::FIREBRICK = Color(0.7f, 0.13f, 0.13f);
	const Color Color::FLORAL_WHITE = Color(1.0f, 0.98f, 0.94f);
	const Color Color::FOREST_GREEN = Color(0.13f, 0.55f, 0.13f);
	const Color Color::FUCHSIA = Color(1.0f, 0.0f, 1.0f);
	const Color Color::GAINSBORO = Color(0.86f, 0.86f, 0.86f);
	const Color Color::GHOST_WHITE = Color(0.97f, 0.97f, 1.0f);
	const Color Color::GOLD = Color(1.0f, 0.84f, 0.0f);
	const Color Color::GOLDENROD = Color(0.85f, 0.65f, 0.13f);
	const Color Color::GRAY = Color(0.75f, 0.75f, 0.75f);
	const Color Color::WEB_GRAY = Color(0.5f, 0.5f, 0.5f);
	const Color Color::GREEN = Color(0.0f, 1.0f, 0.0f);
	const Color Color::WEB_GREEN = Color(0.0f, 0.5f, 0.0f);
	const Color Color::GREEN_YELLOW = Color(0.68f, 1.0f, 0.18f);
	const Color Color::HONEYDEW = Color(0.94f, 1.0f, 0.94f);
	const Color Color::HOT_PINK = Color(1.0f, 0.41f, 0.71f);
	const Color Color::INDIAN_RED = Color(0.8f, 0.36f, 0.36f);
	const Color Color::INDIGO = Color(0.29f, 0.0f, 0.51f);
	const Color Color::IVORY = Color(1.0f, 1.0f, 0.94f);
	const Color Color::KHAKI = Color(0.94f, 0.9f, 0.55f);
	const Color Color::LAVENDER = Color(0.9f, 0.9f, 0.98f);
	const Color Color::LAVENDER_BLUSH = Color(1.0f, 0.94f, 0.96f);
	const Color Color::LAWN_GREEN = Color(0.49f, 0.99f, 0.0f);
	const Color Color::LEMON_CHIFFON = Color(1.0f, 0.98f, 0.8f);
	const Color Color::LIGHT_BLUE = Color(0.68f, 0.85f, 0.9f);
	const Color Color::LIGHT_CORAL = Color(0.94f, 0.5f, 0.5f);
	const Color Color::LIGHT_CYAN = Color(0.88f, 1.0f, 1.0f);
	const Color Color::LIGHT_GOLDENROD = Color(0.98f, 0.98f, 0.82f);
	const Color Color::LIGHT_GRAY = Color(0.83f, 0.83f, 0.83f);
	const Color Color::LIGHT_GREEN = Color(0.56f, 0.93f, 0.56f);
	const Color Color::LIGHT_PINK = Color(1.0f, 0.71f, 0.76f);
	const Color Color::LIGHT_SALMON = Color(1.0f, 0.63f, 0.48f);
	const Color Color::LIGHT_SEA_GREEN = Color(0.13f, 0.7f, 0.67f);
	const Color Color::LIGHT_SKY_BLUE = Color(0.53f, 0.81f, 0.98f);
	const Color Color::LIGHT_SLATE_GRAY = Color(0.47f, 0.53f, 0.6f);
	const Color Color::LIGHT_STEEL_BLUE = Color(0.69f, 0.77f, 0.87f);
	const Color Color::LIGHT_YELLOW = Color(1.0f, 1.0f, 0.88f);
	const Color Color::LIME = Color(0.0f, 1.0f, 0.0f);
	const Color Color::LIME_GREEN = Color(0.2f, 0.8f, 0.2f);
	const Color Color::LINEN = Color(0.98f, 0.94f, 0.9f);
	const Color Color::MAGENTA = Color(1.0f, 0.0f, 1.0f);
	const Color Color::MAROON = Color(0.69f, 0.19f, 0.38f);
	const Color Color::WEB_MAROON = Color(0.5f, 0.0f, 0.0f);
	const Color Color::MEDIUM_AQUAMARINE = Color(0.4f, 0.8f, 0.67f);
	const Color Color::MEDIUM_BLUE = Color(0.0f, 0.0f, 0.8f);
	const Color Color::MEDIUM_ORCHID = Color(0.73f, 0.33f, 0.83f);
	const Color Color::MEDIUM_PURPLE = Color(0.58f, 0.44f, 0.86f);
	const Color Color::MEDIUM_SEA_GREEN = Color(0.24f, 0.7f, 0.44f);
	const Color Color::MEDIUM_SLATE_BLUE = Color(0.48f, 0.41f, 0.93f);
	const Color Color::MEDIUM_SPRING_GREEN = Color(0.0f, 0.98f, 0.6f);
	const Color Color::MEDIUM_TURQUOISE = Color(0.28f, 0.82f, 0.8f);
	const Color Color::MEDIUM_VIOLET_RED = Color(0.78f, 0.08f, 0.52f);
	const Color Color::MIDNIGHT_BLUE = Color(0.1f, 0.1f, 0.44f);
	const Color Color::MINT_CREAM = Color(0.96f, 1.0f, 0.98f);
	const Color Color::MISTY_ROSE = Color(1.0f, 0.89f, 0.88f);
	const Color Color::MOCCASIN = Color(1.0f, 0.89f, 0.71f);
	const Color Color::NAVAJO_WHITE = Color(1.0f, 0.87f, 0.68f);
	const Color Color::NAVY_BLUE = Color(0.0f, 0.0f, 0.5f);
	const Color Color::OLD_LACE = Color(0.99f, 0.96f, 0.9f);
	const Color Color::OLIVE = Color(0.5f, 0.5f, 0.0f);
	const Color Color::OLIVE_DRAB = Color(0.42f, 0.56f, 0.14f);
	const Color Color::ORANGE = Color(1.0f, 0.65f, 0.0f);
	const Color Color::ORANGE_RED = Color(1.0f, 0.27f, 0.0f);
	const Color Color::ORCHID = Color(0.85f, 0.44f, 0.84f);
	const Color Color::PALE_GOLDENROD = Color(0.93f, 0.91f, 0.67f);
	const Color Color::PALE_GREEN = Color(0.6f, 0.98f, 0.6f);
	const Color Color::PALE_TURQUOISE = Color(0.69f, 0.93f, 0.93f);
	const Color Color::PALE_VIOLET_RED = Color(0.86f, 0.44f, 0.58f);
	const Color Color::PAPAYA_WHIP = Color(1.0f, 0.94f, 0.84f);
	const Color Color::PEACH_PUFF = Color(1.0f, 0.85f, 0.73f);
	const Color Color::PERU = Color(0.8f, 0.52f, 0.25f);
	const Color Color::PINK = Color(1.0f, 0.75f, 0.8f);
	const Color Color::PLUM = Color(0.87f, 0.63f, 0.87f);
	const Color Color::POWDER_BLUE = Color(0.69f, 0.88f, 0.9f);
	const Color Color::PURPLE = Color(0.63f, 0.13f, 0.94f);
	const Color Color::WEB_PURPLE = Color(0.5f, 0.0f, 0.5f);
	const Color Color::REBECCA_PURPLE = Color(0.4f, 0.2f, 0.6f);
	const Color Color::RED = Color(1.0f, 0.0f, 0.0f);
	const Color Color::ROSY_BROWN = Color(0.74f, 0.56f, 0.56f);
	const Color Color::ROYAL_BLUE = Color(0.25f, 0.41f, 0.88f);
	const Color Color::SADDLE_BROWN = Color(0.55f, 0.27f, 0.07f);
	const Color Color::SALMON = Color(0.98f, 0.5f, 0.45f);
	const Color Color::SANDY_BROWN = Color(0.96f, 0.64f, 0.38f);
	const Color Color::SEA_GREEN = Color(0.18f, 0.55f, 0.34f);
	const Color Color::SEASHELL = Color(1.0f, 0.96f, 0.93f);
	const Color Color::SIENNA = Color(0.63f, 0.32f, 0.18f);
	const Color Color::SILVER = Color(0.75f, 0.75f, 0.75f);
	const Color Color::SKY_BLUE = Color(0.53f, 0.81f, 0.92f);
	const Color Color::SLATE_BLUE = Color(0.42f, 0.35f, 0.8f);
	const Color Color::SLATE_GRAY = Color(0.44f, 0.5f, 0.56f);
	const Color Color::SNOW = Color(1.0f, 0.98f, 0.98f);
	const Color Color::SPRING_GREEN = Color(0.0f, 1.0f, 0.5f);
	const Color Color::STEEL_BLUE = Color(0.27f, 0.51f, 0.71f);
	const Color Color::TAN = Color(0.82f, 0.71f, 0.55f);
	const Color Color::TEAL = Color(0.0f, 0.5f, 0.5f);
	const Color Color::THISTLE = Color(0.85f, 0.75f, 0.85f);
	const Color Color::TOMATO = Color(1.0f, 0.39f, 0.28f);
	const Color Color::TURQUOISE = Color(0.25f, 0.88f, 0.82f);
	const Color Color::VIOLET = Color(0.93f, 0.51f, 0.93f);
	const Color Color::WHEAT = Color(0.96f, 0.87f, 0.7f);
	const Color Color::WHITE = Color(1.0f, 1.0f, 1.0f);
	const Color Color::WHITE_SMOKE = Color(0.96f, 0.96f, 0.96f);
	const Color Color::YELLOW = Color(1.0f, 1.0f, 0.0f);
	const Color Color::YELLOW_GREEN = Color(0.6f, 0.8f, 0.2f);

	const Color Color::TRANSPARENT = Color(0.0f, 0.0f, 0.0f, 0.0f);
#pragma endregion


	Color::Color(const float red, const float green, const float blue, const float alpha)
	{
		R = red;
		G = green;
		B = blue;
		A = alpha;
	}

	bool Color::TryParse(const std::string &text, Color &color)
	{
		if (text.empty()) return false;

		std::stringstream ss(text);
		std::string element;
		float floats[4] = { 0.0f, 0.0f, 0.0f, 1.0f };

		uint8_t index = 0;
		while (std::getline(ss, element, ','))
		{
			floats[index] = atof(element.c_str());
			index++;
			if (index == 4) break;
		}

		if (index < 3) return false;
		
		color.R = floats[0];
		color.G = floats[1];
		color.B = floats[2];
		color.A = floats[3];
		return true;
	}

	Color Color::Lerp(const Color &start, const Color &end, const float value)
	{
		float red = Math::Lerp(start.R, end.R, value, true);
		float green = Math::Lerp(start.G, end.G, value, true);
		float blue = Math::Lerp(start.B, end.B, value, true);
		float alpha = Math::Lerp(start.A, end.A, value, true);

		return Color(red, green, blue, alpha);
	}

	const Color Color::operator*(const float scalar) const
	{
		Color color = Color(*this);
		color.A *= scalar;
		return color;
	}

	bool Color::operator== (const Color& color) const
	{
		return ((R == color.R) && (G == color.G)
			&& (B == color.B) && (A == color.A));
	}

	bool Color::operator!= (const Color& color) const
	{
		return !((R == color.R) && (G == color.G)
			&& (B == color.B) && (A == color.A));
	}

	std::string Color::ToString() const
	{
		std::ostringstream ss;
		ss << "{ " << "R: " << R << ", G: " << G
			<< "B: " << B << ", A: " << A << " }";
		return ss.str();
	}
}