/*

class Cat
{
	int mAge; // 이 멤버변수는 클래스것이 아닌 인스턴스것

public:
	int GetAge()
	{
		//암시적형변환이 존재
		//그건 this <<
		//this : 객체의 포인터이다
		//왜 포인터인가? : 그이유는 인스턴스가 넘어올때 콜바이 밸류로 들어온다면
		//인스턴스를 복사해야하는데 복사된 인스턴스는 호출된 인스턴스와 다르기때문에
		//콜바이레퍼런스로 불러들어와야한다
		

		//만약 명시적으로 표현한다면?
		//return this->age;
		return mAge; // 그러니 여기서 리턴해주는 mAge는 인스턴스의 것
	}
};

int main()
{
	Cat nacho;
	std::cout << nacho.GetAge() << std::endl;

}
*/