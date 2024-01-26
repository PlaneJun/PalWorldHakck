#pragma once
#include <string>
#include <locale>
#include <windows.h>
#include <stdint.h>


#define CONCAT_IMPL(x, y) x##y
#define MACRO_CONCAT(x, y) CONCAT_IMPL(x, y)
#define PAD(_size) char MACRO_CONCAT(_pad, __COUNTER__)[_size];

class FTextData
{
public:
	char unk[0x28];
	wchar_t* Name;
	__int32 Length;
};

struct FHitResult
{
	PAD(0xE8);
};

struct FText
{
	FTextData* Data;
	char unk[0x10];

	wchar_t* Get() const {
		if (Data)
			return Data->Name;
		return nullptr;
	}
};

struct FFixedPoint64 {
	int64_t Value; // 0x00(0x08)
};

struct FMatrix {
	double m[4][4];
};

struct FVector {
	FVector() : x(), y(), z() { }
	FVector(double _x, double _y, double _z) : x(_x), y(_y), z(_z) { }

	double x, y, z;

	double Size() const { return sqrtf(x * x + y * y + z * z); }

	double DistTo(const FVector& V) const { return (*this - V).Size(); }

	operator bool() { return bool(this->x && this->y && this->z); }
	bool operator==(FVector in) { return bool(this->x == in.x && this->y == in.y && this->z == in.z); }
	FVector operator+(FVector in) { return FVector(this->x + in.x, this->y + in.y, this->z + in.z); }
	FVector operator-(FVector in) { return FVector(this->x - in.x, this->y - in.y, this->z - in.z); }
	FVector operator-(const FVector& other) const { return FVector(x - other.x, y - other.y, z - other.z); }

};

struct FVector2D {

	double x, y;

	FVector2D() : x(0.f), y(0.f) {}
	FVector2D(double X, double Y) : x(X), y(Y) {}
	double Size() const { return sqrt(x * x + y * y); }
	double DistTo(const FVector2D& V) const { return (*this - V).Size(); }
	bool IsValid() {
		return x != NULL && y != NULL;
	}
	double distance() {
		return sqrt(this->x * this->x + this->y * this->y);
	}
	FVector2D operator + (const FVector2D& other) const { return FVector2D(x + other.x, y + other.y); }
	FVector2D operator + (double scalar) const { return FVector2D(x + scalar, y + scalar); }
	FVector2D operator- (const FVector2D& other) const { return FVector2D(x - other.x, y - other.y); }
	FVector2D operator- (double scalar) const { return FVector2D(x - scalar, y - scalar); }
	FVector2D operator* (double scalar) const { return FVector2D(x * scalar, y * scalar); }
	FVector2D operator/ (double scalar) const { return FVector2D(x / scalar, y / scalar); }
	friend bool operator>(const FVector2D& one, const FVector2D& two) { return one.x > two.x && one.y > two.y; }
	friend bool operator<(const FVector2D& one, const FVector2D& two) { return one.x < two.x&& one.y < two.y; }
	friend bool operator>=(const FVector2D& one, const FVector2D& two) { return one.x >= two.x && one.y >= two.y; }
	friend bool operator<=(const FVector2D& one, const FVector2D& two) { return one.x <= two.x && one.y <= two.y; }
	bool operator!=(const FVector2D& V) const { return x != V.x && y != V.y; }
	bool operator==(const FVector2D& V) const { return x == V.x && y == V.y; }
};

struct FRotator {
	FRotator() : pitch(), yaw(), roll() { }
	FRotator(float _pitch, float _yaw, float _roll) : pitch(_pitch), yaw(_yaw), roll(_roll) { }

	float pitch, yaw, roll;

	operator bool() { return bool(this->pitch && this->yaw); }
	bool operator==(FRotator in) { return bool(this->pitch == in.pitch && this->yaw == in.yaw && this->roll == in.roll); }
	FRotator operator+(FRotator in) { return FRotator(this->pitch + in.pitch, this->yaw + in.yaw, this->roll + in.roll); }
	FRotator operator-(FRotator in) { return FRotator(this->pitch - in.pitch, this->yaw - in.yaw, this->roll - in.roll); }
};

struct FLinearColor {
	FLinearColor() : r(), g(), b(), a() { }
	FLinearColor(float _r, float _g, float _b, float _a) : r(_r), g(_g), b(_b), a(_a) { }

	float r, g, b, a;

	operator bool() { return bool(this->r || this->g || this->b || this->a); }
	bool operator==(FLinearColor in) { return bool(this->r == in.r && this->g == in.g && this->b == in.b && this->a == in.a); }
};

template<class T>
struct TArray
{
	friend struct FString;
public:
	inline TArray()
	{
		Data = nullptr;
		Count = Max = 0;
	};

	inline int Num() const
	{
		return Count;
	};

	inline T& operator[](int i)
	{
		return Data[i];
	};

	inline const T& operator[](int i) const
	{
		return Data[i];
	};

	inline bool IsValidIndex(int i) const
	{
		return i < Num();
	}
public:
	T* Data;
	unsigned int Count;
	unsigned int Max;
};

struct FString : private TArray<wchar_t> {
public:
	FString() = default;

	FString(const wchar_t* other)
	{
		Max = Count = *other ? std::wcslen(other) + 1 : 0;

		if (Count)
		{
			Data = const_cast<wchar_t*>(other);
		}
	};

	FString(const wchar_t* other, int count)
	{
		Data = const_cast<wchar_t*>(other);;
		Max = Count = count;
	};

	inline bool IsValid() const
	{
		return Data != nullptr;
	}

	inline const wchar_t* c_str() const
	{
		return Data;
	}

	std::string ToString();

	int multi(char* name, int size) const
	{
		return WideCharToMultiByte(CP_UTF8, 0, Data, Count, name, size, nullptr, nullptr) - 1;
	}
};

inline std::string FString::ToString() {
	auto length = std::wcslen(Data);
	std::string str(length, '\0');
	std::use_facet<std::ctype<wchar_t>>(std::locale()).narrow(Data, Data + length, '?', &str[0]);

	return str;
}

class FNameEntry
{
public:
	uint16_t bIsWide : 1;
	uint16_t lOWERCASEpROBEhAS : 5;
	uint16_t Len : 10;

	union
	{
		char AnsiName[1024];
		wchar_t	WideName[1024];
	};

	inline std::string String()
	{
		if (bIsWide) { return std::string(); }
		return { AnsiName, Len };
	}
};

struct FNameEntryHandle {
	uint32_t Block = 0;
	uint32_t Offset = 0;

	FNameEntryHandle(uint32_t block, uint32_t offset) : Block(block), Offset(offset) {};
	FNameEntryHandle(uint32_t id) : Block(id >> 16), Offset(id & 65535) {};
	operator uint32_t() const { return (Block << 16 | Offset); }
};

struct FNamePool
{
	BYTE Lock[8];
	uint32_t CurrentBlock;
	uint32_t CurrentByteCursor;
	BYTE* Blocks[8192];

	inline FNameEntry* GetEntry(FNameEntryHandle handle)
	{
		return reinterpret_cast<FNameEntry*>(Blocks[handle.Block] + 2 * static_cast<uint64_t>(handle.Offset));
	}
};

struct FName {
	uint32_t Index;
	uint32_t Number;
	static inline FNamePool* FNamePoolDate = nullptr;

	inline std::string GetName()const
	{
		auto entry = FNamePoolDate->GetEntry(Index);
		auto name = entry->String();
		if (Number > 0)
		{
			name += "_" + std::to_string(Number);
		}
		auto pos = name.rfind('/');
		if (pos != std::string::npos)
		{
			name = name.substr(pos + 1);
		}
		return name;
	}
};

struct FKey {
	FName name;
	uint8_t datails[0x10];
};

struct FBox {
	FVector Min;
	FVector Max;

	FBox() {

		Min.x = NULL;
		Min.y = NULL;
		Min.z = NULL;

		Max.x = NULL;
		Max.y = NULL;
		Max.z = NULL;
	}
};

enum BoneFNames {
	Root,
	pelvis,
	spine_01,
	spine_02,
	spine_03,
	clavicle_l,
	upperarm_l,
	lowerarm_l,
	hand_l,
	index_01_l,
	index_02_l,
	index_03_l,
	middle_01_l,
	middle_02_l,
	middle_03_l,
	pinky_01_l,
	pinky_02_l,
	pinky_03_l,
	ring_01_l,
	ring_02_l,
	ring_03_l,
	thumb_01_l,
	thumb_02_l,
	thumb_03_l,
	weapon_l,
	lowerarm_twist_01_l,
	upperarm_twist_01_l,
	neck_01,
	head,
	eyes_l,
	eyes_r,
	clavicle_r,
	upperarm_r,
	lowerarm_r,
	hand_r,
	index_01_r,
	index_02_r,
	index_03_r,
	middle_01_r,
	middle_02_r,
	middle_03_r,
	pinky_01_r,
	pinky_02_r,
	pinky_03_r,
	ring_01_r,
	ring_02_r,
	ring_03_r,
	thumb_01_r,
	thumb_02_r,
	thumb_03_r,
	weapon_r,
	lowerarm_twist_01_r,
	upperarm_twist_01_r,
	F_OldCloth001_bag_01,
	thigh_l,
	calf_l,
	calf_twist_01_l,
	foot_l,
	ball_l,
	thigh_twist_01_l,
	thigh_r,
	calf_r,
	calf_twist_01_r,
	foot_r,
	ball_r,
	thigh_twist_01_r,
	F_OldCloth001_04,
	F_OldCloth001_05,
	F_OldCloth001_06,
	F_OldCloth001_07,
	F_OldCloth001_01,
	F_OldCloth001_02,
	F_OldCloth001_03
};


