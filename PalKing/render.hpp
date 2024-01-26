#include <string>
#include "engine.h"

namespace Colors
{
	FLinearColor Text{ 1.0f, 1.0f, 1.0f, 1.0f };
	FLinearColor Text_Shadow{ 0.0f, 0.0f, 0.0f, 0.0f };
	FLinearColor Text_Outline{ 0.0f, 0.0f, 0.0f, 0.30f };

	FLinearColor Window_Background{ 0.009f, 0.009f, 0.009f, 1.0f };
	FLinearColor Window_Header{ 1, 0.0784, 0.5765,1 };

	FLinearColor Button_Idle{ 0.5451, 0.4902, 0.4824,1 };
	FLinearColor Button_Hovered{ 0.22f, 0.30f, 0.72f, 1.0f };
	FLinearColor Button_Active{ 1, 0.0784, 0.5765,1 };

	FLinearColor Checkbox_Idle{ 0.17f, 0.16f, 0.23f, 1.0f };
	FLinearColor Checkbox_Hovered{ 0.22f, 0.30f, 0.72f, 1.0f };
	FLinearColor Checkbox_Enabled{ 1, 0.0784, 0.5765,1 };

	FLinearColor Combobox_Idle{ 0.17f, 0.16f, 0.23f, 1.0f };
	FLinearColor Combobox_Hovered{ 0.17f, 0.16f, 0.23f, 1.0f };
	FLinearColor Combobox_Elements{ 0.239f, 0.42f, 0.82f, 1.0f };

	FLinearColor Slider_Idle{ 0.17f, 0.16f, 0.23f, 1.0f };
	FLinearColor Slider_Hovered{ 0.17f, 0.16f, 0.23f, 1.0f };
	FLinearColor Slider_Progress{ 1, 0.0784, 0.5765,1 };
	FLinearColor Slider_Button{ 1, 0.0784, 0.5765,1 };

	FLinearColor ColorPicker_Background{ 0.006f, 0.006f, 0.006f, 1.0f };

	FLinearColor Snow{ 1, 0.9804, 0.9804,1 };
	FLinearColor GhostWhite{ 0.9725, 0.9725, 1,1 };
	FLinearColor WhiteSmoke{ 0.9608, 0.9608, 0.9608,1 };
	FLinearColor Gainsboro{ 0.8627, 0.8627, 0.8627,1 };
	FLinearColor FloralWhite{ 1, 0.9804, 0.9412,1 };
	FLinearColor OldLace{ 0.9922, 0.9608, 0.902,1 };
	FLinearColor Linen{ 0.9804, 0.9412, 0.902,1 };
	FLinearColor AntiqueWhite{ 0.9804, 0.9216, 0.8431,1 };
	FLinearColor PapayaWhip{ 1, 0.9373, 0.8353,1 };
	FLinearColor BlanchedAlmond{ 1, 0.9216, 0.8039,1 };
	FLinearColor Bisque{ 1, 0.8941, 0.7686,1 };
	FLinearColor PeachPuff{ 1, 0.8549, 0.7255,1 };
	FLinearColor NavajoWhite{ 1, 0.8706, 0.6784,1 };
	FLinearColor Moccasin{ 1, 0.8941, 0.7098,1 };
	FLinearColor Cornsilk{ 1, 0.9725, 0.8627,1 };
	FLinearColor Ivory{ 1, 1, 0.9412,1 };
	FLinearColor LemonChiffon{ 1, 0.9804, 0.8039,1 };
	FLinearColor Seashell{ 1, 0.9608, 0.9333,1 };
	FLinearColor Honeydew{ 0.9412, 1, 0.9412,1 };
	FLinearColor MintCream{ 0.9608, 1, 0.9804,1 };
	FLinearColor Azure{ 0.9412, 1, 1,1 };
	FLinearColor AliceBlue{ 0.9412, 0.9725, 1,1 };
	FLinearColor lavender{ 0.902, 0.902, 0.9804,1 };
	FLinearColor LavenderBlush{ 1, 0.9412, 0.9608,1 };
	FLinearColor MistyRose{ 1, 0.8941, 0.8824,1 };
	FLinearColor White{ 1, 1, 1,1 };
	FLinearColor WhiteA{ 1, 1, 1,0.5 };
	FLinearColor Black{ 0, 0, 0,1 };
	FLinearColor Black1{ 0, 0, 0,0.5 };
	FLinearColor DarkSlateGray{ 0.1843, 0.3098, 0.3098,1 };
	FLinearColor DimGrey{ 0.4118, 0.4118, 0.4118,1 };
	FLinearColor SlateGrey{ 0.4392, 0.502, 0.5647,1 };
	FLinearColor LightSlateGray{ 0.4667, 0.5333, 0.6,1 };
	FLinearColor Grey{ 0.7451, 0.7451, 0.7451,1 };
	FLinearColor LightGray{ 0.8275, 0.8275, 0.8275,1 };
	FLinearColor LightGray1{ 0.8275, 0.8275, 0.8275,0.2 };
	FLinearColor MidnightBlue{ 0.098, 0.098, 0.4392,1 };
	FLinearColor NavyBlue{ 0, 0, 0.502,1 };
	FLinearColor CornflowerBlue{ 0.3922, 0.5843, 0.9294,1 };
	FLinearColor DarkSlateBlue{ 0.2824, 0.2392, 0.5451,1 };
	FLinearColor SlateBlue{ 0.4157, 0.3529, 0.8039,1 };
	FLinearColor MediumSlateBlue{ 0.4824, 0.4078, 0.9333,1 };
	FLinearColor LightSlateBlue{ 0.5176, 0.4392, 1,1 };
	FLinearColor MediumBlue{ 0, 0, 0.8039,1 };
	FLinearColor RoyalBlue{ 0.2549, 0.4118, 0.8824,1 };
	FLinearColor Blue{ 0, 0, 1,1 };
	FLinearColor DodgerBlue{ 0.1176, 0.5647, 1,1 };
	FLinearColor DeepSkyBlue{ 0, 0.749, 1,1 };
	FLinearColor SkyBlue{ 0.5294, 0.8078, 0.9216,1 };
	FLinearColor LightSkyBlue{ 0.5294, 0.8078, 0.9804,1 };
	FLinearColor SteelBlue{ 0.2745, 0.5098, 0.7059,1 };
	FLinearColor LightSteelBlue{ 0.6902, 0.7686, 0.8706,1 };
	FLinearColor LightBlue{ 0.6784, 0.8471, 0.902,1 };
	FLinearColor PowderBlue{ 0.6902, 0.8784, 0.902,1 };
	FLinearColor PaleTurquoise{ 0.6863, 0.9333, 0.9333,1 };
	FLinearColor DarkTurquoise{ 0, 0.8078, 0.8196,1 };
	FLinearColor MediumTurquoise{ 0.2824, 0.8196, 0.8,1 };
	FLinearColor Turquoise{ 0.251, 0.8784, 0.8157,1 };
	FLinearColor Cyan{ 0, 1, 1,1 };
	FLinearColor LightCyan{ 0.8784, 1, 1,1 };
	FLinearColor CadetBlue{ 0.3725, 0.6196, 0.6275,1 };
	FLinearColor MediumAquamarine{ 0.4, 0.8039, 0.6667,1 };
	FLinearColor Aquamarine{ 0.498, 1, 0.8314,1 };
	FLinearColor DarkGreen{ 0, 0.3922, 0,1 };
	FLinearColor DarkOliveGreen{ 0.3333, 0.4196, 0.1843,1 };
	FLinearColor DarkSeaGreen{ 0.5608, 0.7373, 0.5608,1 };
	FLinearColor SeaGreen{ 0.1804, 0.5451, 0.3412,1 };
	FLinearColor MediumSeaGreen{ 0.2353, 0.702, 0.4431,1 };
	FLinearColor LightSeaGreen{ 0.1255, 0.698, 0.6667,1 };
	FLinearColor PaleGreen{ 0.5961, 0.9843, 0.5961,1 };
	FLinearColor SpringGreen{ 0, 1, 0.498,1 };
	FLinearColor LawnGreen{ 0.4863, 0.9882, 0,1 };
	FLinearColor Green{ 0, 1, 0,1 };
	FLinearColor Chartreuse{ 0.498, 1, 0,1 };
	FLinearColor MedSpringGreen{ 0, 0.9804, 0.6039,0.5 };
	FLinearColor GreenYellow{ 0.6784, 1, 0.1843,1 };
	FLinearColor LimeGreen{ 0.1961, 0.8039, 0.1961,1 };
	FLinearColor YellowGreen{ 0.6039, 0.8039, 0.1961,1 };
	FLinearColor ForestGreen{ 0.1333, 0.5451, 0.1333,1 };
	FLinearColor OliveDrab{ 0.4196, 0.5569, 0.1373,1 };
	FLinearColor DarkKhaki{ 0.7412, 0.7176, 0.4196,1 };
	FLinearColor PaleGoldenrod{ 0.9333, 0.9098, 0.6667,1 };
	FLinearColor LtGoldenrodYello{ 0.9804, 0.9804, 0.8235,1 };
	FLinearColor LightYellow{ 1, 1, 0.8784,1 };
	FLinearColor Yellow{ 1, 1, 0,1 };
	FLinearColor Gold{ 1, 0.8431, 0,1 };
	FLinearColor LightGoldenrod{ 0.9333, 0.8667, 0.5098,1 };
	FLinearColor goldenrod{ 0.8549, 0.6471, 0.1255,1 };
	FLinearColor DarkGoldenrod{ 0.7216, 0.5255, 0.0431,1 };
	FLinearColor RosyBrown{ 0.7373, 0.5608, 0.5608,1 };
	FLinearColor IndianRed{ 0.8039, 0.3608, 0.3608,1 };
	FLinearColor SaddleBrown{ 0.5451, 0.2706, 0.0745,1 };
	FLinearColor Sienna{ 0.6275, 0.3216, 0.1765,1 };
	FLinearColor Peru{ 0.8039, 0.5216, 0.2471,1 };
	FLinearColor Burlywood{ 0.8706, 0.7216, 0.5294,1 };
	FLinearColor Beige{ 0.9608, 0.9608, 0.8627,1 };
	FLinearColor Wheat{ 0.9608, 0.8706, 0.702,1 };
	FLinearColor SandyBrown{ 0.9569, 0.6431, 0.3765,1 };
	FLinearColor Tan{ 0.8235, 0.7059, 0.549,1 };
	FLinearColor Chocolate{ 0.8235, 0.4118, 0.1176,1 };
	FLinearColor Firebrick{ 0.698, 0.1333, 0.1333,1 };
	FLinearColor Brown{ 0.6471, 0.1647, 0.1647,1 };
	FLinearColor DarkSalmon{ 0.9137, 0.5882, 0.4784,1 };
	FLinearColor Salmon{ 0.9804, 0.502, 0.4471,1 };
	FLinearColor LightSalmon{ 1, 0.6275, 0.4784,1 };
	FLinearColor Orange{ 1, 0.6471, 0,1 };
	FLinearColor DarkOrange{ 1, 0.549, 0,1 };
	FLinearColor Coral{ 1, 0.498, 0.3137,1 };
	FLinearColor LightCoral{ 0.9412, 0.502, 0.502,1 };
	FLinearColor Tomato{ 1, 0.3882, 0.2784,1 };
	FLinearColor OrangeRed{ 1, 0.2706, 0,1 };
	FLinearColor Red{ 1, 0, 0,1 };
	FLinearColor HotPink{ 1, 0.4118, 0.7059,1 };
	FLinearColor DeepPink{ 1, 0.0784, 0.5765,1 };
	FLinearColor Pink{ 1, 0.7529, 0.7961,1 };
	FLinearColor LightPink{ 1, 0.7137, 0.7569,1 };
	FLinearColor PaleVioletRed{ 0.8588, 0.4392, 0.5765,1 };
	FLinearColor Maroon{ 0.6902, 0.1882, 0.3765,1 };
	FLinearColor MediumVioletRed{ 0.7804, 0.0824, 0.5216,1 };
	FLinearColor VioletRed{ 0.8157, 0.1255, 0.5647,1 };
	FLinearColor Magenta{ 1, 0, 1,1 };
	FLinearColor Violet{ 0.9333, 0.5098, 0.9333,1 };
	FLinearColor Plum{ 0.8667, 0.6275, 0.8667,1 };
	FLinearColor Orchid{ 0.8549, 0.4392, 0.8392,1 };
	FLinearColor MediumOrchid{ 0.7294, 0.3333, 0.8275,1 };
	FLinearColor DarkOrchid{ 0.6, 0.1961, 0.8,1 };
	FLinearColor DarkViolet{ 0.5804, 0, 0.8275,1 };
	FLinearColor BlueViolet{ 0.5412, 0.1686, 0.8863,1 };
	FLinearColor Purple{ 0.6275, 0.1255, 0.9412,1 };
	FLinearColor MediumPurple{ 0.5765, 0.4392, 0.8588,1 };
	FLinearColor Thistle{ 0.8471, 0.749, 0.8471,1 };
	FLinearColor Snow1{ 1, 0.9804, 0.9804,1 };
	FLinearColor Snow2{ 0.9333, 0.9137, 0.9137,1 };
	FLinearColor Snow3{ 0.8039, 0.7882, 0.7882,1 };
	FLinearColor Snow4{ 0.5451, 0.5373, 0.5373,1 };
	FLinearColor Seashell1{ 1, 0.9608, 0.9333,1 };
	FLinearColor Seashell2{ 0.9333, 0.898, 0.8706,1 };
	FLinearColor Seashell3{ 0.8039, 0.7725, 0.749,1 };
	FLinearColor Seashell4{ 0.5451, 0.5255, 0.5098,1 };
	FLinearColor AntiqueWhite1{ 1, 0.9373, 0.8588,1 };
	FLinearColor AntiqueWhite2{ 0.9333, 0.8745, 0.8,1 };
	FLinearColor AntiqueWhite3{ 0.8039, 0.7529, 0.6902,1 };
	FLinearColor AntiqueWhite4{ 0.5451, 0.5137, 0.4706,1 };
	FLinearColor Bisque1{ 1, 0.8941, 0.7686,1 };
	FLinearColor Bisque2{ 0.9333, 0.8353, 0.7176,1 };
	FLinearColor Bisque3{ 0.8039, 0.7176, 0.6196,1 };
	FLinearColor Bisque4{ 0.5451, 0.4902, 0.4196,1 };
	FLinearColor PeachPuff1{ 1, 0.8549, 0.7255,1 };
	FLinearColor PeachPuff2{ 0.9333, 0.7961, 0.6784,1 };
	FLinearColor PeachPuff3{ 0.8039, 0.6863, 0.5843,1 };
	FLinearColor PeachPuff4{ 0.5451, 0.4667, 0.3961,1 };
	FLinearColor NavajoWhite1{ 1, 0.8706, 0.6784,1 };
	FLinearColor NavajoWhite2{ 0.9333, 0.8118, 0.6314,1 };
	FLinearColor NavajoWhite3{ 0.8039, 0.702, 0.5451,1 };
	FLinearColor NavajoWhite4{ 0.5451, 0.4745, 0.3686,1 };
	FLinearColor LemonChiffon1{ 1, 0.9804, 0.8039,1 };
	FLinearColor LemonChiffon2{ 0.9333, 0.9137, 0.749,1 };
	FLinearColor LemonChiffon3{ 0.8039, 0.7882, 0.6471,1 };
	FLinearColor LemonChiffon4{ 0.5451, 0.5373, 0.4392,1 };
	FLinearColor Cornsilk1{ 1, 0.9725, 0.8627,1 };
	FLinearColor Cornsilk2{ 0.9333, 0.9098, 0.8039,1 };
	FLinearColor Cornsilk3{ 0.8039, 0.7843, 0.6941,1 };
	FLinearColor Cornsilk4{ 0.5451, 0.5333, 0.4706,1 };
	FLinearColor Ivory1{ 1, 1, 0.9412,1 };
	FLinearColor Ivory2{ 0.9333, 0.9333, 0.8784,1 };
	FLinearColor Ivory3{ 0.8039, 0.8039, 0.7569,1 };
	FLinearColor Ivory4{ 0.5451, 0.5451, 0.5137,1 };
	FLinearColor Honeydew1{ 0.9412, 1, 0.9412,1 };
	FLinearColor Honeydew2{ 0.8784, 0.9333, 0.8784,1 };
	FLinearColor Honeydew3{ 0.7569, 0.8039, 0.7569,1 };
	FLinearColor Honeydew4{ 0.5137, 0.5451, 0.5137,1 };
	FLinearColor LavenderBlush1{ 1, 0.9412, 0.9608,1 };
	FLinearColor LavenderBlush2{ 0.9333, 0.8784, 0.898,1 };
	FLinearColor LavenderBlush3{ 0.8039, 0.7569, 0.7725,1 };
	FLinearColor LavenderBlush4{ 0.5451, 0.5137, 0.5255,1 };
	FLinearColor MistyRose1{ 1, 0.8941, 0.8824,1 };
	FLinearColor MistyRose2{ 0.9333, 0.8353, 0.8235,1 };
	FLinearColor MistyRose3{ 0.8039, 0.7176, 0.7098,1 };
	FLinearColor MistyRose4{ 0.5451, 0.4902, 0.4824,1 };
	FLinearColor Azure1{ 0.9412, 1, 1,1 };
	FLinearColor Azure2{ 0.8784, 0.9333, 0.9333,1 };
	FLinearColor Azure3{ 0.7569, 0.8039, 0.8039,1 };
	FLinearColor Azure4{ 0.5137, 0.5451, 0.5451,1 };
	FLinearColor SlateBlue1{ 0.5137, 0.4353, 1,1 };
	FLinearColor SlateBlue2{ 0.4784, 0.4039, 0.9333,1 };
	FLinearColor SlateBlue3{ 0.4118, 0.349, 0.8039,1 };
	FLinearColor SlateBlue4{ 0.2784, 0.2353, 0.5451,1 };
	FLinearColor RoyalBlue1{ 0.2824, 0.4627, 1,1 };
	FLinearColor RoyalBlue2{ 0.2627, 0.4314, 0.9333,1 };
	FLinearColor RoyalBlue3{ 0.2275, 0.3725, 0.8039,1 };
	FLinearColor RoyalBlue4{ 0.1529, 0.251, 0.5451,1 };
	FLinearColor Blue1{ 0, 0, 1,1 };
	FLinearColor Blue2{ 0, 0, 0.9333,1 };
	FLinearColor Blue3{ 0, 0, 0.8039,1 };
	FLinearColor Blue4{ 0, 0, 0.5451,1 };
	FLinearColor DodgerBlue1{ 0.1176, 0.5647, 1,1 };
	FLinearColor DodgerBlue2{ 0.1098, 0.5255, 0.9333,1 };
	FLinearColor DodgerBlue3{ 0.0941, 0.4549, 0.8039,1 };
	FLinearColor DodgerBlue4{ 0.0627, 0.3059, 0.5451,1 };
	FLinearColor SteelBlue1{ 0.3882, 0.7216, 1,1 };
	FLinearColor SteelBlue2{ 0.3608, 0.6745, 0.9333,1 };
	FLinearColor SteelBlue3{ 0.3098, 0.5804, 0.8039,1 };
	FLinearColor SteelBlue4{ 0.2118, 0.3922, 0.5451,1 };
	FLinearColor DeepSkyBlue1{ 0, 0.749, 1,1 };
	FLinearColor DeepSkyBlue2{ 0, 0.698, 0.9333,1 };
	FLinearColor DeepSkyBlue3{ 0, 0.6039, 0.8039,1 };
	FLinearColor DeepSkyBlue4{ 0, 0.4078, 0.5451,1 };
	FLinearColor SkyBlue1{ 0.5294, 0.8078, 1,1 };
	FLinearColor SkyBlue2{ 0.4941, 0.7529, 0.9333,1 };
	FLinearColor SkyBlue3{ 0.4235, 0.651, 0.8039,1 };
	FLinearColor SkyBlue4{ 0.2902, 0.4392, 0.5451,1 };
	FLinearColor LightSkyBlue1{ 0.6902, 0.8863, 1,1 };
	FLinearColor LightSkyBlue2{ 0.6431, 0.8275, 0.9333,1 };
	FLinearColor LightSkyBlue3{ 0.5529, 0.7137, 0.8039,1 };
	FLinearColor LightSkyBlue4{ 0.3765, 0.4824, 0.5451,1 };
	FLinearColor SlateGray1{ 0.7765, 0.8863, 1,1 };
	FLinearColor SlateGray2{ 0.7255, 0.8275, 0.9333,1 };
	FLinearColor SlateGray3{ 0.6235, 0.7137, 0.8039,1 };
	FLinearColor SlateGray4{ 0.4235, 0.4824, 0.5451,1 };
	FLinearColor LightSteelBlue1{ 0.7922, 0.8824, 1,1 };
	FLinearColor LightSteelBlue2{ 0.7373, 0.8235, 0.9333,1 };
	FLinearColor LightSteelBlue3{ 0.6353, 0.7098, 0.8039,1 };
	FLinearColor LightSteelBlue4{ 0.4314, 0.4824, 0.5451,1 };
	FLinearColor LightBlue1{ 0.749, 0.9373, 1,1 };
	FLinearColor LightBlue2{ 0.698, 0.8745, 0.9333,1 };
	FLinearColor LightBlue3{ 0.6039, 0.7529, 0.8039,1 };
	FLinearColor LightBlue4{ 0.4078, 0.5137, 0.5451,1 };
	FLinearColor LightCyan1{ 0.8784, 1, 1,1 };
	FLinearColor LightCyan2{ 0.8196, 0.9333, 0.9333,1 };
	FLinearColor LightCyan3{ 0.7059, 0.8039, 0.8039,1 };
	FLinearColor LightCyan4{ 0.4784, 0.5451, 0.5451,1 };
	FLinearColor PaleTurquoise1{ 0.7333, 1, 1,1 };
	FLinearColor PaleTurquoise2{ 0.6824, 0.9333, 0.9333,1 };
	FLinearColor PaleTurquoise3{ 0.5882, 0.8039, 0.8039,1 };
	FLinearColor PaleTurquoise4{ 0.4, 0.5451, 0.5451,1 };
	FLinearColor CadetBlue1{ 0.5961, 0.9608, 1,1 };
	FLinearColor CadetBlue2{ 0.5569, 0.898, 0.9333,1 };
	FLinearColor CadetBlue3{ 0.4784, 0.7725, 0.8039,1 };
	FLinearColor CadetBlue4{ 0.3255, 0.5255, 0.5451,1 };
	FLinearColor Turquoise1{ 0, 0.9608, 1,1 };
	FLinearColor Turquoise2{ 0, 0.898, 0.9333,1 };
	FLinearColor Turquoise3{ 0, 0.7725, 0.8039,1 };
	FLinearColor Turquoise4{ 0, 0.5255, 0.5451,1 };
	FLinearColor Cyan1{ 0, 1, 1,1 };
	FLinearColor Cyan2{ 0, 0.9333, 0.9333,1 };
	FLinearColor Cyan3{ 0, 0.8039, 0.8039,1 };
	FLinearColor Cyan4{ 0, 0.5451, 0.5451,1 };
	FLinearColor DarkSlateGray1{ 0.5922, 1, 1,1 };
	FLinearColor DarkSlateGray2{ 0.5529, 0.9333, 0.9333,1 };
	FLinearColor DarkSlateGray3{ 0.4745, 0.8039, 0.8039,1 };
	FLinearColor DarkSlateGray4{ 0.3216, 0.5451, 0.5451,1 };
	FLinearColor Aquamarine1{ 0.498, 1, 0.8314,1 };
	FLinearColor Aquamarine2{ 0.4627, 0.9333, 0.7765,1 };
	FLinearColor Aquamarine3{ 0.4, 0.8039, 0.6667,1 };
	FLinearColor Aquamarine4{ 0.2706, 0.5451, 0.4549,1 };
	FLinearColor DarkSeaGreen1{ 0.7569, 1, 0.7569,1 };
	FLinearColor DarkSeaGreen2{ 0.7059, 0.9333, 0.7059,1 };
	FLinearColor DarkSeaGreen3{ 0.6078, 0.8039, 0.6078,1 };
	FLinearColor DarkSeaGreen4{ 0.4118, 0.5451, 0.4118,1 };
	FLinearColor SeaGreen1{ 0.3294, 1, 0.6235,1 };
	FLinearColor SeaGreen2{ 0.3059, 0.9333, 0.5804,1 };
	FLinearColor SeaGreen3{ 0.2627, 0.8039, 0.502,1 };
	FLinearColor SeaGreen4{ 0.1804, 0.5451, 0.3412,1 };
	FLinearColor PaleGreen1{ 0.6039, 1, 0.6039,1 };
	FLinearColor PaleGreen2{ 0.5647, 0.9333, 0.5647,1 };
	FLinearColor PaleGreen3{ 0.4863, 0.8039, 0.4863,1 };
	FLinearColor PaleGreen4{ 0.3294, 0.5451, 0.3294,1 };
	FLinearColor SpringGreen1{ 0, 1, 0.498,1 };
	FLinearColor SpringGreen2{ 0, 0.9333, 0.4627,1 };
	FLinearColor SpringGreen3{ 0, 0.8039, 0.4,1 };
	FLinearColor SpringGreen4{ 0, 0.5451, 0.2706,1 };
	FLinearColor Green1{ 0, 1, 0,1 };
	FLinearColor Green2{ 0, 0.9333, 0,1 };
	FLinearColor Green3{ 0, 0.8039, 0,1 };
	FLinearColor Green4{ 0, 0.5451, 0,1 };
	FLinearColor Chartreuse1{ 0.498, 1, 0,1 };
	FLinearColor Chartreuse2{ 0.4627, 0.9333, 0,1 };
	FLinearColor Chartreuse3{ 0.4, 0.8039, 0,1 };
	FLinearColor Chartreuse4{ 0.2706, 0.5451, 0,1 };
	FLinearColor OliveDrab1{ 0.7529, 1, 0.2431,1 };
	FLinearColor OliveDrab2{ 0.702, 0.9333, 0.2275,1 };
	FLinearColor OliveDrab3{ 0.6039, 0.8039, 0.1961,1 };
	FLinearColor OliveDrab4{ 0.4118, 0.5451, 0.1333,1 };
	FLinearColor DarkOliveGreen1{ 0.7922, 1, 0.4392,1 };
	FLinearColor DarkOliveGreen2{ 0.7373, 0.9333, 0.4078,1 };
	FLinearColor DarkOliveGreen3{ 0.6353, 0.8039, 0.3529,1 };
	FLinearColor DarkOliveGreen4{ 0.4314, 0.5451, 0.2392,1 };
	FLinearColor Khaki1{ 1, 0.9647, 0.5608,1 };
	FLinearColor Khaki2{ 0.9333, 0.902, 0.5216,1 };
	FLinearColor Khaki3{ 0.8039, 0.7765, 0.451,1 };
	FLinearColor Khaki4{ 0.5451, 0.5255, 0.3059,1 };
	FLinearColor LightGoldenrod1{ 1, 0.9255, 0.5451,1 };
	FLinearColor LightGoldenrod2{ 0.9333, 0.8627, 0.5098,1 };
	FLinearColor LightGoldenrod3{ 0.8039, 0.7451, 0.4392,1 };
	FLinearColor LightGoldenrod4{ 0.5451, 0.5059, 0.298,1 };
	FLinearColor LightYellow1{ 1, 1, 0.8784,1 };
	FLinearColor LightYellow2{ 0.9333, 0.9333, 0.8196,1 };
	FLinearColor LightYellow3{ 0.8039, 0.8039, 0.7059,1 };
	FLinearColor LightYellow4{ 0.5451, 0.5451, 0.4784,1 };
	FLinearColor Yellow1{ 1, 1, 0,1 };
	FLinearColor Yellow2{ 0.9333, 0.9333, 0,1 };
	FLinearColor Yellow3{ 0.8039, 0.8039, 0,1 };
	FLinearColor Yellow4{ 0.5451, 0.5451, 0,1 };
	FLinearColor Gold1{ 1, 0.8431, 0,1 };
	FLinearColor Gold2{ 0.9333, 0.7882, 0,1 };
	FLinearColor Gold3{ 0.8039, 0.6784, 0,1 };
	FLinearColor Gold4{ 0.5451, 0.4588, 0,1 };
	FLinearColor Goldenrod1{ 1, 0.7569, 0.1451,1 };
	FLinearColor Goldenrod2{ 0.9333, 0.7059, 0.1333,1 };
	FLinearColor Goldenrod3{ 0.8039, 0.6078, 0.1137,1 };
	FLinearColor Goldenrod4{ 0.5451, 0.4118, 0.0784,1 };
	FLinearColor DarkGoldenrod1{ 1, 0.7255, 0.0588,1 };
	FLinearColor DarkGoldenrod2{ 0.9333, 0.6784, 0.0549,1 };
	FLinearColor DarkGoldenrod3{ 0.8039, 0.5843, 0.0471,1 };
	FLinearColor DarkGoldenrod4{ 0.5451, 0.3961, 0.0314,1 };
	FLinearColor RosyBrown1{ 1, 0.7569, 0.7569,1 };
	FLinearColor RosyBrown2{ 0.9333, 0.7059, 0.7059,1 };
	FLinearColor RosyBrown3{ 0.8039, 0.6078, 0.6078,1 };
	FLinearColor RosyBrown4{ 0.5451, 0.4118, 0.4118,1 };
	FLinearColor IndianRed1{ 1, 0.4157, 0.4157,1 };
	FLinearColor IndianRed2{ 0.9333, 0.3882, 0.3882,1 };
	FLinearColor IndianRed3{ 0.8039, 0.3333, 0.3333,1 };
	FLinearColor IndianRed4{ 0.5451, 0.2275, 0.2275,1 };
	FLinearColor Sienna1{ 1, 0.5098, 0.2784,1 };
	FLinearColor Sienna2{ 0.9333, 0.4745, 0.2588,1 };
	FLinearColor Sienna3{ 0.8039, 0.4078, 0.2235,1 };
	FLinearColor Sienna4{ 0.5451, 0.2784, 0.149,1 };
	FLinearColor Burlywood1{ 1, 0.8275, 0.6078,1 };
	FLinearColor Burlywood2{ 0.9333, 0.7725, 0.5686,1 };
	FLinearColor Burlywood3{ 0.8039, 0.6667, 0.4902,1 };
	FLinearColor Burlywood4{ 0.5451, 0.451, 0.3333,1 };
	FLinearColor Wheat1{ 1, 0.9059, 0.7294,1 };
	FLinearColor Wheat2{ 0.9333, 0.8471, 0.6824,1 };
	FLinearColor Wheat3{ 0.8039, 0.7294, 0.5882,1 };
	FLinearColor Wheat4{ 0.5451, 0.4941, 0.4,1 };
	FLinearColor Tan1{ 1, 0.6471, 0.3098,1 };
	FLinearColor Tan2{ 0.9333, 0.6039, 0.2863,1 };
	FLinearColor Tan3{ 0.8039, 0.5216, 0.2471,1 };
	FLinearColor Tan4{ 0.5451, 0.3529, 0.1686,1 };
	FLinearColor Chocolate1{ 1, 0.498, 0.1412,1 };
	FLinearColor Chocolate2{ 0.9333, 0.4627, 0.1294,1 };
	FLinearColor Chocolate3{ 0.8039, 0.4, 0.1137,1 };
	FLinearColor Chocolate4{ 0.5451, 0.2706, 0.0745,1 };
	FLinearColor Firebrick1{ 1, 0.1882, 0.1882,1 };
	FLinearColor Firebrick2{ 0.9333, 0.1725, 0.1725,1 };
	FLinearColor Firebrick3{ 0.8039, 0.149, 0.149,1 };
	FLinearColor Firebrick4{ 0.5451, 0.102, 0.102,1 };
	FLinearColor Brown1{ 1, 0.251, 0.251,1 };
	FLinearColor Brown2{ 0.9333, 0.2314, 0.2314,1 };
	FLinearColor Brown3{ 0.8039, 0.2, 0.2,1 };
	FLinearColor Brown4{ 0.5451, 0.1373, 0.1373,1 };
	FLinearColor Salmon1{ 1, 0.549, 0.4118,1 };
	FLinearColor Salmon2{ 0.9333, 0.5098, 0.3843,1 };
	FLinearColor Salmon3{ 0.8039, 0.4392, 0.3294,1 };
	FLinearColor Salmon4{ 0.5451, 0.298, 0.2235,1 };
	FLinearColor LightSalmon1{ 1, 0.6275, 0.4784,1 };
	FLinearColor LightSalmon2{ 0.9333, 0.5843, 0.4471,1 };
	FLinearColor LightSalmon3{ 0.8039, 0.5059, 0.3843,1 };
	FLinearColor LightSalmon4{ 0.5451, 0.3412, 0.2588,1 };
	FLinearColor Orange1{ 1, 0.6471, 0,1 };
	FLinearColor Orange2{ 0.9333, 0.6039, 0,1 };
	FLinearColor Orange3{ 0.8039, 0.5216, 0,1 };
	FLinearColor Orange4{ 0.5451, 0.3529, 0,1 };
	FLinearColor DarkOrange1{ 1, 0.498, 0,1 };
	FLinearColor DarkOrange2{ 0.9333, 0.4627, 0,1 };
	FLinearColor DarkOrange3{ 0.8039, 0.4, 0,1 };
	FLinearColor DarkOrange4{ 0.5451, 0.2706, 0,1 };
	FLinearColor Coral1{ 1, 0.4471, 0.3373,1 };
	FLinearColor Coral2{ 0.9333, 0.4157, 0.3137,1 };
	FLinearColor Coral3{ 0.8039, 0.3569, 0.2706,1 };
	FLinearColor Coral4{ 0.5451, 0.2431, 0.1843,1 };
	FLinearColor Tomato1{ 1, 0.3882, 0.2784,1 };
	FLinearColor Tomato2{ 0.9333, 0.3608, 0.2588,1 };
	FLinearColor Tomato3{ 0.8039, 0.3098, 0.2235,1 };
	FLinearColor Tomato4{ 0.5451, 0.2118, 0.149,1 };
	FLinearColor OrangeRed1{ 1, 0.2706, 0,1 };
	FLinearColor OrangeRed2{ 0.9333, 0.251, 0,1 };
	FLinearColor OrangeRed3{ 0.8039, 0.2157, 0,1 };
	FLinearColor OrangeRed4{ 0.5451, 0.1451, 0,1 };
	FLinearColor Red1{ 1, 0, 0,1 };
	FLinearColor Red2{ 0.9333, 0, 0,1 };
	FLinearColor Red3{ 0.8039, 0, 0,1 };
	FLinearColor Red4{ 0.5451, 0, 0,1 };
	FLinearColor DeepPink1{ 1, 0.0784, 0.5765,1 };
	FLinearColor DeepPink2{ 0.9333, 0.0706, 0.5373,1 };
	FLinearColor DeepPink3{ 0.8039, 0.0627, 0.4627,1 };
	FLinearColor DeepPink4{ 0.5451, 0.0392, 0.3137,1 };
	FLinearColor HotPink1{ 1, 0.4314, 0.7059,1 };
	FLinearColor HotPink2{ 0.9333, 0.4157, 0.6549,1 };
	FLinearColor HotPink3{ 0.8039, 0.3765, 0.5647,1 };
	FLinearColor HotPink4{ 0.5451, 0.2275, 0.3843,1 };
	FLinearColor Pink1{ 1, 0.7098, 0.7725,1 };
	FLinearColor Pink2{ 0.9333, 0.6627, 0.7216,1 };
	FLinearColor Pink3{ 0.8039, 0.5686, 0.6196,1 };
	FLinearColor Pink4{ 0.5451, 0.3882, 0.4235,1 };
	FLinearColor LightPink1{ 1, 0.6824, 0.7255,1 };
	FLinearColor LightPink2{ 0.9333, 0.6353, 0.6784,1 };
	FLinearColor LightPink3{ 0.8039, 0.549, 0.5843,1 };
	FLinearColor LightPink4{ 0.5451, 0.3725, 0.3961,1 };
	FLinearColor PaleVioletRed1{ 1, 0.5098, 0.6706,1 };
	FLinearColor PaleVioletRed2{ 0.9333, 0.4745, 0.6235,1 };
	FLinearColor PaleVioletRed3{ 0.8039, 0.4078, 0.5373,1 };
	FLinearColor PaleVioletRed4{ 0.5451, 0.2784, 0.3647,1 };
	FLinearColor Maroon1{ 1, 0.2039, 0.702,1 };
	FLinearColor Maroon2{ 0.9333, 0.1882, 0.6549,1 };
	FLinearColor Maroon3{ 0.8039, 0.1608, 0.5647,1 };
	FLinearColor Maroon4{ 0.5451, 0.1098, 0.3843,1 };
	FLinearColor VioletRed1{ 1, 0.2431, 0.5882,1 };
	FLinearColor VioletRed2{ 0.9333, 0.2275, 0.549,1 };
	FLinearColor VioletRed3{ 0.8039, 0.1961, 0.4706,1 };
	FLinearColor VioletRed4{ 0.5451, 0.1333, 0.3216,1 };
	FLinearColor Magenta1{ 1, 0, 1,1 };
	FLinearColor Magenta2{ 0.9333, 0, 0.9333,1 };
	FLinearColor Magenta3{ 0.8039, 0, 0.8039,1 };
	FLinearColor Magenta4{ 0.5451, 0, 0.5451,1 };
	FLinearColor Orchid1{ 1, 0.5137, 0.9804,1 };
	FLinearColor Orchid2{ 0.9333, 0.4784, 0.9137,1 };
	FLinearColor Orchid3{ 0.8039, 0.4118, 0.7882,1 };
	FLinearColor Orchid4{ 0.5451, 0.2784, 0.5373,1 };
	FLinearColor Plum1{ 1, 0.7333, 1,1 };
	FLinearColor Plum2{ 0.9333, 0.6824, 0.9333,1 };
	FLinearColor Plum3{ 0.8039, 0.5882, 0.8039,1 };
	FLinearColor Plum4{ 0.5451, 0.4, 0.5451,1 };
	FLinearColor MediumOrchid1{ 0.8784, 0.4, 1,1 };
	FLinearColor MediumOrchid2{ 0.8196, 0.3725, 0.9333,1 };
	FLinearColor MediumOrchid3{ 0.7059, 0.3216, 0.8039,1 };
	FLinearColor MediumOrchid4{ 0.4784, 0.2157, 0.5451,1 };
	FLinearColor DarkOrchid1{ 0.749, 0.2431, 1,1 };
	FLinearColor DarkOrchid2{ 0.698, 0.2275, 0.9333,1 };
	FLinearColor DarkOrchid3{ 0.6039, 0.1961, 0.8039,1 };
	FLinearColor DarkOrchid4{ 0.4078, 0.1333, 0.5451,1 };
	FLinearColor Purple1{ 0.6078, 0.1882, 1,1 };
	FLinearColor Purple2{ 0.5686, 0.1725, 0.9333,1 };
	FLinearColor Purple3{ 0.4902, 0.149, 0.8039,1 };
	FLinearColor Purple4{ 0.3333, 0.102, 0.5451,1 };
	FLinearColor MediumPurple1{ 0.6706, 0.5098, 1,1 };
	FLinearColor MediumPurple2{ 0.6235, 0.4745, 0.9333,1 };
	FLinearColor MediumPurple3{ 0.5373, 0.4078, 0.8039,1 };
	FLinearColor MediumPurple4{ 0.3647, 0.2784, 0.5451,1 };
	FLinearColor Thistle1{ 1, 0.8824, 1,1 };
	FLinearColor Thistle2{ 0.9333, 0.8235, 0.9333,1 };
	FLinearColor Thistle3{ 0.8039, 0.7098, 0.8039,1 };
	FLinearColor Thistle4{ 0.5451, 0.4824, 0.5451,1 };
	FLinearColor grey11{ 0.1098, 0.1098, 0.1098,1 };
	FLinearColor grey21{ 0.2118, 0.2118, 0.2118,1 };
	FLinearColor grey31{ 0.3098, 0.3098, 0.3098,1 };
	FLinearColor grey41{ 0.4118, 0.4118, 0.4118,1 };
	FLinearColor grey51{ 0.5098, 0.5098, 0.5098,1 };
	FLinearColor grey61{ 0.6118, 0.6118, 0.6118,1 };
	FLinearColor grey71{ 0.7098, 0.7098, 0.7098,1 };
	FLinearColor gray81{ 0.8118, 0.8118, 0.8118,1 };
	FLinearColor gray91{ 0.9098, 0.9098, 0.9098,1 };
	FLinearColor DarkGrey{ 0.6627, 0.6627, 0.6627,1 };
	FLinearColor DarkBlue{ 0, 0, 0.5451,1 };
	FLinearColor DarkCyan{ 0, 0.5451, 0.5451,1 };
	FLinearColor DarkMagenta{ 0.5451, 0, 0.5451,1 };
	FLinearColor DarkRed{ 0.5451, 0, 0,1 };
	FLinearColor LightGreen{ 0.5647, 0.9333, 0.5647,1 };
	FLinearColor None{ 0,0,0,1 };

}


namespace settings {

	namespace bones
	{
		bool head = true;
		bool neck = false;
		bool torso = false;
		bool pelvis = false;
	}

	namespace players {
		bool 显示玩家 = false;
		bool 显示怪物 = false;
		bool 显示名字 = false;
		bool 显示距离 = false;
		bool 显示血量 = false;
		bool 秒杀 = false;
		bool 无敌 = false;
		bool 无限体力 = false;
		bool 加速 = false;
		bool 飞刀 = false;
		bool 游戏亮度=false;
		float 亮度值 = 1.f;
		float 加速倍数 = 1.f;
		float 秒杀值 = 100.f;
		float 秒杀倍数 = 1.f;
	}

	namespace style {
		bool text_outlined = false;
		float font_size = 1.f;
	}

}

namespace render {
	bool show_menu = true;
	bool show_menu_old = true;
	int hovered_headers = 0;
	APlayerController* controller;
	UCanvas* canvas;
	UObject* font;
	UObject* deftexture;
	UWorld* world;
	FVector2D screen_center, screen_size;
	int viptime;

	bool is_insert_clicked()
	{
		static bool insert_clicked = false;
		static bool insert_down_already = false;
		bool insert_down = GetAsyncKeyState(VK_HOME) & 1;

		if (insert_down) {
			if (insert_down_already)
				insert_clicked = false;
			else {
				insert_clicked = true;
				insert_down_already = true;
			}
		}
		else {
			insert_clicked = false;
			insert_down_already = false;
		}

		return insert_clicked;
	}

	bool is_delete_clicked()
	{
		static bool delete_clicked = false;
		static bool delete_down_already = false;
		bool delete_down = GetAsyncKeyState(VK_END) & 1;

		if (delete_down) {
			if (delete_down_already)
				delete_clicked = false;
			else {
				delete_clicked = true;
				delete_down_already = true;
			}
		}
		else {
			delete_clicked = false;
			delete_down_already = false;
		}

		return delete_clicked;
	}

	bool in_circl(int cx, int cy, int r, int x, int y) {
		int dist = (x - cx) * (x - cx) + (y - cy) * (y - cy);
		if (dist <= r * r)
			return true;
		else
			return false;
	}

	void text(FString content, FVector2D position, FLinearColor render_color, float Fontsize, bool center_x, bool center_y, bool outlined) {
		if (outlined)
			canvas->k2_draw_text(font, content, position, FVector2D(Fontsize, Fontsize), render_color, 1.0f, FLinearColor(), FVector2D(), center_x, center_y, true, { 0,0,0,1 });
		else
			canvas->k2_draw_text(font, content, position, FVector2D(Fontsize, Fontsize), render_color, 1.0f, FLinearColor(), FVector2D(), center_x, center_y, false, FLinearColor());

	}

	FVector2D text_siz(FString content) {
		return canvas->k2_text_size(font, content, FVector2D(settings::style::font_size, settings::style::font_size));
	}

	void line(FVector2D a, FVector2D b, FLinearColor render_color, float thickness) {
		canvas->k2_draw_line(a, b, thickness, render_color);
	}

	void DrawBox(FVector2D ScreenPosition, FVector2D ScreenSize, float Thickness, FLinearColor RenderColor, bool outline, FLinearColor outlineColor)
	{
		canvas->K2_DrawBox(ScreenPosition, ScreenSize, Thickness, RenderColor);

		if (outline)
		{
			ScreenPosition = ScreenPosition - (1.0f * Thickness);
			ScreenSize = ScreenSize + (2.0f * Thickness);
			canvas->K2_DrawBox(ScreenPosition, ScreenSize, Thickness, outlineColor);
			ScreenPosition = ScreenPosition + (2.0f * Thickness);
			ScreenSize = ScreenSize - (4.0f * Thickness);
			canvas->K2_DrawBox(ScreenPosition, ScreenSize, Thickness, outlineColor);
		}
	}

	void circle(FVector2D position, int radius, int segments, FLinearColor color) {
		float PI = 3.1415927f;

		float Step = PI * 2.0 / segments;
		int Count = 0;
		FVector2D V[128];
		for (float a = 0; a < PI * 2.0; a += Step) {
			float X1 = radius * defines::math->cos(a) + position.x;
			float Y1 = radius * defines::math->sin(a) + position.y;
			float X2 = radius * defines::math->cos(a + Step) + position.x;
			float Y2 = radius * defines::math->sin(a + Step) + position.y;
			V[Count].x = X1;
			V[Count].y = Y1;
			V[Count + 1].x = X2;
			V[Count + 1].y = Y2;
			line(FVector2D{ V[Count].x, V[Count].y }, FVector2D{ X2, Y2 }, color, 1.f);
		}
	}

	void filled_box(FVector2D position, FVector2D size, FLinearColor render_color) {
		for (int i = 0; i < size.y; i++) {
			canvas->k2_draw_line(FVector2D(position.x, position.y + i), FVector2D(position.x + size.x, position.y + i), 1.f, render_color);
		}
	}

	void mouse_cursor() {
		auto cursor = render::controller->get_mouse_position();
		filled_box(FVector2D(cursor.x - 2.5, cursor.y - 2.5), FVector2D(10, 10), FLinearColor(0.93f, 0.47f, 0.258f, 1.f));
	}

	class menu_column {
	public:
		bool is_collapsed() {
			return this->collapsed;
		}

		bool in_area(FVector2D pos, FVector2D size) {
			if (this->cursor_pos.x > pos.x && this->cursor_pos.y > pos.y)
				if (this->cursor_pos.x < pos.x + size.x && this->cursor_pos.y < pos.y + size.y)
					return true;

			return false;
		}

		void checkbox(FString text, bool* option) {
			FVector2D current = menu_pos + menu_offset;
			FVector2D size = FVector2D(this->menu_size.x - (this->wide_offset * 2), 35);
			render::canvas->K2_DrawBox(current, size, 1, Colors::WhiteA);
			bool hovered = in_area(current, size);
			bool down = hovered && this->mouse_down;
			bool clicked = hovered && this->mouse_clicked;

			FLinearColor render_color = FLinearColor();
			if (*option)
				render_color = FLinearColor(0.2f, 0.075f, 0.175f, 1.f);

			if (render_color)
				render::filled_box({ current.x + 5,current.y + 5 }, { size.x - 10,size.y - 10 }, render_color);
			auto temp = *option ? L"     ON" : L"    OFF";
			wchar_t tempA[64] = {};
			swprintf_s(tempA, L"%ws%ws", text.c_str(), temp);
			render::text(tempA, FVector2D(current.x + size.x / 2, current.y + 9), Colors::White, 1.f, true, false, false);

			if (clicked) *option = !*option;

			this->menu_offset.y += 35;
		}

		void slider(FString textA, float min, float max, float* value, bool round) {
			FVector2D current = menu_pos + menu_offset;
			FVector2D size = FVector2D(this->menu_size.x - (this->wide_offset * 2), 35);
			render::canvas->K2_DrawBox(current, size, 1, Colors::WhiteA);
			bool hovered = in_area(current, size);
			bool down = hovered && this->mouse_down;

			if (hovered && down) {
				*value = ((this->cursor_pos.x - current.x) * ((max - min) / size.x)) + min;
				if (round)*value = defines::math->round(*value);
				if (*value < min) *value = min;
				if (*value > max) *value = max;
			}

			FLinearColor render_color = FLinearColor(0.2f, 0.075f, 0.175f, 1.f);
			double oneP = (size.x - 10) / (max - min);
			render::filled_box({ current.x + 5,current.y + 5 }, FVector2D(oneP * (*value - min), size.y - 10), render_color);
			std::wstring temp = {};
			if (round)
				temp = textA.c_str() + std::to_wstring((int)*value);
			else
				temp = textA.c_str() + std::to_wstring(*value);

			render::text(temp.c_str(), FVector2D(current.x + size.x / 2, current.y + 9), FLinearColor(1.f, 1.f, 1.f, 1.f), 1.f, true, false, false);
			this->menu_offset.y += 35;
		}

		void ColorEdit(FString textA, int i, float* value, FLinearColor render_color)
		{
			FVector2D current = menu_pos + menu_offset;
			FVector2D size = FVector2D(this->menu_size.x - (this->wide_offset * 2), 8);

			bool hovered = in_area({ current.x,current.y + i * 20 }, { size.x,8 });
			bool down = hovered && this->mouse_down;


			if (hovered && down) {
				*value = ((this->cursor_pos.x - current.x) * (255 / size.x)) / 255;
				if (*value < 0) *value = 0;
				if (*value > 1) *value = 1;
			}

			double oneP = (size.x - 20) / 255;
			render::filled_box({ current.x + 10,current.y + i * 20 }, FVector2D(oneP * (*value * 255), 8), render_color);
			std::wstring temp = textA.c_str() + std::to_wstring(int(*value * 255));
			render::text(temp.c_str(), FVector2D(current.x + size.x / 2, current.y + i * 18), FLinearColor(1.f, 1.f, 1.f, 1.f), 0.8f, true, false, true);
		}

		void coloredit(FString textA, FLinearColor* value) {
			FVector2D current = menu_pos + menu_offset;
			FVector2D size = FVector2D(this->menu_size.x - (this->wide_offset * 2), 80);
			render::text(textA, FVector2D(current.x + size.x / 2, current.y + 3), FLinearColor(1.f, 1.f, 1.f, 1.f), 0.8f, true, false, false);
			render::canvas->K2_DrawBox(current, size, 1, Colors::White);
			ColorEdit((L"R:"), 1, &value->r, Colors::Red);
			ColorEdit((L"G:"), 2, &value->g, Colors::Green);
			ColorEdit((L"B:"), 3, &value->b, Colors::Blue);
			render::filled_box({ current.x + 100,current.y + 6 }, FVector2D(8, 8), { value->r ,value->g ,value->b ,1 });
			render::canvas->K2_DrawBox({ current.x + 100,current.y + 6 }, FVector2D(8, 8), 1, Colors::White);
			this->menu_offset.y += 80;
		}

		bool invisible_button(FVector2D size, bool* hovered) {
			FVector2D current = menu_pos + menu_offset;

			*hovered = in_area(current, size);
			bool clicked = *hovered && this->mouse_clicked;

			return clicked;
		}

		bool invisible_r_button(FVector2D size, bool* hovered) {
			FVector2D current = menu_pos + menu_offset;

			*hovered = in_area(current, size);
			bool clicked = *hovered && this->mouse_rmb_clicked;

			return clicked;
		}

		void handle_input() {
			this->cursor_pos = render::controller->get_mouse_position();
			this->mouse_rmb_down = GetAsyncKeyState(2) != 0;
			if (this->mouse_rmb_down) {
				if (this->mouse_rmb_down_already)
					this->mouse_rmb_clicked = false;
				else {
					this->mouse_rmb_clicked = true;
					this->mouse_rmb_down_already = true;
				}
			}
			else {
				this->mouse_rmb_clicked = false;
				this->mouse_rmb_down_already = false;
			}
			this->mouse_down = GetAsyncKeyState(1) != 0;
			if (this->mouse_down) {
				if (this->mouse_down_already)
					this->mouse_clicked = false;
				else {
					this->mouse_clicked = true;
					this->mouse_down_already = true;
				}
			}
			else {
				this->mouse_clicked = false;
				this->mouse_down_already = false;
			}
		}

		bool begin(FString title, FVector2D pos, FVector2D size, FLinearColor header_color) {
			if (!this->once) {
				this->menu_pos = pos;
				this->menu_size = size;

				this->wide_offset = 8;

				this->header_color = header_color;

				this->collapsed = false;
				this->once = true;
			}

			this->menu_offset = FVector2D();

			this->handle_input();

			bool header_hovered = false;
			bool header_clicked = invisible_r_button(FVector2D(this->menu_size.x, 40), &header_hovered);
			if (header_clicked) this->collapsed = !this->collapsed;

			//fix menu moving
			if (header_hovered) {
				render::hovered_headers += 1;
			}

			//menu moving
			{
				static FVector2D static_cursor = FVector2D();
				static FVector2D static_calculated = FVector2D();

				if (render::hovered_headers == 1 && header_hovered && this->mouse_down) {
					if (static_cursor == FVector2D())
						static_cursor = this->cursor_pos;

					if (static_calculated == FVector2D())
						static_calculated = static_cursor - this->menu_pos;

					this->menu_pos = this->cursor_pos - static_calculated;
				}

				if (!this->mouse_down) {
					static_cursor = FVector2D();
					static_calculated = FVector2D();
				}
			}

			//header rendering
			{
				FLinearColor header_color = FLinearColor(0.025f, 0.025f, 0.025f, 1.f);
				if (!this->collapsed)
					header_color = this->header_color;

				render::filled_box(this->menu_pos, FVector2D(this->menu_size.x, 40), header_color);
				render::text(title.c_str(), FVector2D(this->menu_pos.x + (this->menu_size.x / 2), this->menu_pos.y + 12), FLinearColor(0.9f, 0.9f, 0.9f, 0.9f), 1.f, true, false, false);
			}

			//background rendering
			if (!this->collapsed) {
				FLinearColor background_color = FLinearColor(0.025f, 0.025f, 0.025f, 1.f);
				render::filled_box(FVector2D(this->menu_pos.x + this->wide_offset, this->menu_pos.y + 40), FVector2D(this->menu_size.x - (this->wide_offset * 2), this->menu_size.y), background_color);

				this->menu_offset = FVector2D(this->wide_offset, 40);
			}

			return true;
		}

		bool end() {
			return true;
		}
	private:
		float world_delta_time;

		double wide_offset;

		bool anim_opening;
		bool anim_closing;

		bool once;
		bool collapsed;

		bool mouse_rmb_clicked;
		bool mouse_rmb_down;
		bool mouse_rmb_down_already;

		bool mouse_clicked;
		bool mouse_down;
		bool mouse_down_already;

		FVector2D cursor_pos;
		FVector2D menu_pos;
		FVector2D menu_size;
		FVector2D menu_offset;
		double real_menu_size_y;

		FLinearColor header_color;
	};

	void draw_menu()
	{
		if (render::is_insert_clicked()) render::show_menu = !render::show_menu;

		if (render::show_menu) {
			render::hovered_headers = 0;

			render::text((L"提示：\n鼠标左键开关功能\nHome 隐藏/显示菜单,End 退出辅助\n\n无敌:进入服务器前打开，进入服务器后关闭(进入服务器后看到几万的血量代表开启ok).\n\n秒杀/秒采集:\n\t1)、需要有武器,拳头不能秒采集\n\t2)、开了后切换身上的武器(对每把武器进行设置)之后就可以关闭了,一直有效.\n\t3)、更换新武器或者新工具,需要重新打开设置\n\t4)、设置好了请关闭,不然骑宝宝时会崩"), FVector2D(10, 20), Colors::Green, 1.f, false, false, true);

			static render::menu_column players;
			players.begin((L"辅 助 设 置"), FVector2D(255, 0), FVector2D(300, 35 * 15), FLinearColor(0.175f, 0.12f, 0.075f, 1.f));
			if (!players.is_collapsed())
			{
				players.checkbox((L"显示玩家"), &settings::players::显示玩家);
				players.checkbox((L"显示怪物"), &settings::players::显示怪物);
				players.checkbox((L"显示名字"), &settings::players::显示名字);
				players.checkbox((L"显示距离"), &settings::players::显示距离);
				players.checkbox((L"显示血量"), &settings::players::显示血量);
				players.checkbox((L"无敌(可多人)"), &settings::players::无敌);
				players.checkbox((L"无限体力(可多人)"), &settings::players::无限体力);
				players.checkbox((L"攻击加速(攻击时按住波浪键)"), &settings::players::加速);
				players.checkbox((L"游戏亮度"), &settings::players::游戏亮度);
				players.slider((L"亮度值: "), 1, 20, &settings::players::亮度值, false);
				players.slider((L"人物/攻击倍速: "), 1, 20, &settings::players::加速倍数, false);
				players.checkbox((L"飞刀: "), &settings::players::飞刀);
				players.checkbox((L"秒杀/秒采集"), &settings::players::秒杀);
				players.slider((L"秒杀值: "), 1, 10000, &settings::players::秒杀值, false);
				players.slider((L"秒杀倍数: "), 1, 1000, &settings::players::秒杀倍数, false);
			}
			players.end();

			render::mouse_cursor();
		}
	}
}
