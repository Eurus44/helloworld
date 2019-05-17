#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;
using namespace sf;


class Levels
{

	string name;
	Sprite spbg;
	Texture txbg;
public:

	Levels() {
		name = '\0';
	}

	Levels(string adress, string name) {
		this->name = name;
		txbg.loadFromFile(adress);
		spbg.setTexture(txbg);
	}

	~Levels() {
		name = '\0';
	}


	void setPosition() {

		Vector2f targetSize(1366.0f, 768.0f);

		spbg.setScale(
			targetSize.x / spbg.getLocalBounds().width,
			targetSize.y / spbg.getLocalBounds().height);
	}


	void setName(string name) {
		this->name = name;
	}

	void setTxbg(string adress) {

		this->txbg.loadFromFile(adress);
	}


	Sprite getspbg() {
		return spbg;
	}

	string getName() {
		return name;
	}
};
class mainmenu:public Levels
{

private:

	Font font;
	Text title;
	Text ply;
	Text ins;
	Text exi;
public:
	mainmenu(string adress = "Assets/mainMenu.gif", string name = "Main Menu") :Levels(adress,name) {

		font.loadFromFile("Assets/SouthernAire.ttf");

	}

	~mainmenu() {
		setTxbg("NULL");
		setName("NULL");
	}


	Text gettitle() {
		return title;
	}

	Text getPlay() {
		return ply;
	}

	Text getInstruction() {
		return ins;
	}

	Text getExit() {
		return exi;
	}

	void draw() {

		title.setFont(font);
		title.setString("Street Fighter!");
		title.setPosition(300.0f, 50.0f);
		title.setColor(Color::White);
		title.setCharacterSize(172);


		ply.setFont(font);
		ply.setString("Play");
		ply.setPosition(575.0f, 300.0f);

		IntRect rect2(ply.getPosition().x + 5, ply.getPosition().y + 5, ply.getGlobalBounds().width + 5, ply.getGlobalBounds().height + 5);


		if (rect2.contains(Mouse::getPosition()))
			ply.setColor(Color::Yellow);

		else
			ply.setColor(Color::White);

		ply.setCharacterSize(72);


		ins.setFont(font);
		ins.setString("Instruction");
		ins.setPosition(575.0f, 450.0f);
		sf::IntRect rect1(ins.getPosition().x + 5, ins.getPosition().y + 5, ins.getGlobalBounds().width + 5, ins.getGlobalBounds().height + 5);


		if (rect1.contains(Mouse::getPosition()))
			ins.setColor(Color::Yellow);

		else
			ins.setColor(Color::White);

		ins.setCharacterSize(72);


		exi.setFont(font);
		exi.setString("Exit");
		exi.setPosition(575.0f, 600.0f);
		sf::IntRect rect(exi.getPosition().x + 5, exi.getPosition().y + 5, exi.getGlobalBounds().width + 5, exi.getGlobalBounds().height + 5);


		if (rect.contains(Mouse::getPosition()))
			exi.setColor(Color::Yellow);

		else
			exi.setColor(Color::White);

		exi.setCharacterSize(72);
	}

	bool play() {

		IntRect rect1(ply.getPosition().x + 5, ply.getPosition().y + 5, ply.getGlobalBounds().width + 5, ply.getGlobalBounds().height + 5);

		if (Mouse::isButtonPressed(Mouse::Left))
			if (rect1.contains(Mouse::getPosition()))
				return true;

		return false;
	}

	bool instructions() {

		IntRect rect1(ins.getPosition().x + 5, ins.getPosition().y + 5, ins.getGlobalBounds().width + 5, ins.getGlobalBounds().height + 5);

		if (Mouse::isButtonPressed(Mouse::Left))
			if (rect1.contains(Mouse::getPosition()))
				return true;

		return false;
	}

	bool exit() {
		IntRect rect(exi.getPosition().x + 5, exi.getPosition().y + 5, exi.getGlobalBounds().width + 5, exi.getGlobalBounds().height + 5);

		if (Mouse::isButtonPressed(Mouse::Left))
			if (rect.contains(Mouse::getPosition()))
				return true;

		return false;
	}
};
class Instruction:public Levels
{

private:

	Font font;
	Text tx[7];
	Texture txbg;
public:
	Instruction(string adress = "Assets/insSpirits.gif", string name = "Instructions") :Levels(adress,name) {
		font.loadFromFile("Assets/david.ttf");
	}

	~Instruction() {
		setTxbg("NULL");
		setName("NULL");
	}


	Text getTx(int i) {
		return tx[i];
	}

	bool back() {

		IntRect rect(tx[6].getPosition().x + 5, tx[6].getPosition().y + 5, tx[6].getGlobalBounds().width + 5, tx[6].getGlobalBounds().height + 5);
		if (Mouse::isButtonPressed(Mouse::Left))
			if (rect.contains(Mouse::getPosition()))
				return true;

		return false;
	}

	void draw() {
		for (int i = 0; i < 7; i++) {
			tx[i].setFont(font);
			tx[i].setColor(Color::White);
			tx[i].setCharacterSize(24);
		}


		tx[0].setString("Instruction");
		tx[0].setPosition(300.0f, 50.0f);
		tx[0].setCharacterSize(172);

		tx[1].setString("Player 1: Arrow Keys to Move Character");
		tx[1].setPosition(250.0f, 250.0f);

		tx[2].setString("Player 1: Use A to Punch , S To Kick , D To Combo , F To Block");
		tx[2].setPosition(250.0f, 300.f);

		tx[3].setString("Player 2: Use V to Punch , B To Kick , N To Combo , M To Block ");
		tx[3].setPosition(250.0f, 350.0f);

		tx[4].setString("Player 2: Use J To move Forward , L to move Backward");
		tx[4].setPosition(250.0f, 400.0f);

		tx[5].setString("Player 2: Use I to Jump , K to Sit");
		tx[5].setPosition(250.0f, 450.0f);

		tx[6].setString("Back!");
		tx[6].setPosition(250.0f, 550.0f);

		IntRect rect2(tx[6].getPosition().x + 5, tx[6].getPosition().y + 5, tx[6].getGlobalBounds().width + 5, tx[6].getGlobalBounds().height + 5);

		if (rect2.contains(Mouse::getPosition()))
			tx[6].setColor(Color::Yellow);

		else
			tx[6].setColor(Color::White);

		tx[6].setCharacterSize(50);
	}
};
class characters
{

private:
	string name;
protected:

	Sprite *sprite;
	Texture *texture;
public:
	characters() {
		this->name = "\0";
	}

	characters(string name) {
		this->name = name;
	}

	~characters() {
		this->name = "\0";
	}

	string getName() {
		return this->name;
	}

	Texture geTexture(int i) {
		return texture[i];
	}

	Sprite getSprite(int i) {
		return sprite[i];
	}
};
class Iori :public characters
{

	int health;

	Vector2f targetSize;
	Vector2f pos;
public:
	Iori(string name = "IORI") :characters(name) {

		texture = new Texture[223];
		sprite = new Sprite[223];

		pos.x = 100.0f;
		pos.y = 365.0f;
		targetSize.x = 140.0f;//250
		targetSize.y = 240.0f;//400

		health = 100;

// load ready OK

		for (int i = 0; i < 10; ++i)
		{

			texture[i].loadFromFile("AssetsNew/Iori/ioriReady/ready (" + to_string(i + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}
// load idle OK

        for (int i = 10; i < 19; ++i)
		{

		    int k=10;
			texture[i].loadFromFile("AssetsNew/Iori/ioriIdle/idle (" + to_string(i -k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
			//sprite.setSize(100, 200);
		}
// load duck OK
        for (int i = 19; i < 34; ++i)
		{
		    int k=19;
			texture[i].loadFromFile("AssetsNew/Iori/ioriDuck/duck (" + to_string(i -k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}
// load walk Front OK
        for (int i = 34; i < 44; ++i)
		{
		    int k=34;
			texture[i].loadFromFile("AssetsNew/Iori/ioriWalkFront/walkFront (" + to_string(i -k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}
// walk back OK
        for (int i = 44; i < 53; ++i)
		{
		    int k=44;
			texture[i].loadFromFile("AssetsNew/Iori/ioriWalkBack/walkBack (" + to_string(i -k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}
// Jump Ok
        for (int i = 53; i <116 ; ++i)
		{
		    int k=53;
			texture[i].loadFromFile("AssetsNew/Iori/ioriJump/jump (" + to_string(i -k + 1) + ").png");
			sprite[i].setTexture(texture[i]);

		}
// Punch OK
        for (int i = 116; i < 129; ++i)
		{
		    int k=116;
			texture[i].loadFromFile("AssetsNew/Iori/ioriPunch/punch (" + to_string(i -k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}
// Kick OK
        for (int i = 129; i < 144; ++i)
		{
		    int k=129;
			texture[i].loadFromFile("AssetsNew/Iori/ioriKick/kick (" + to_string(i -k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}
// combo OK
        for (int i = 144; i < 196; ++i)
		{
		    int k=144;
			texture[i].loadFromFile("AssetsNew/Iori/ioriCombo/combo (" + to_string(i -k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}
// Block
        for (int i = 196; i < 207; ++i)
		{
		    int k=196;
			texture[i].loadFromFile("AssetsNew/Iori/ioriBlock/block (" + to_string(i -k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}
// dead
        for (int i = 207; i < 223; ++i)
		{
		    int k=207;
			texture[i].loadFromFile("AssetsNew/Iori/ioriDead/dead (" + to_string(i -k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}


	}

	~Iori() {
		health = 0;
	}

	void setHealth(int health) {
		this->health = health;
	}

	int getHealth()const {
		return health;
	}

	void Ready(bool status) {
		if (status == true)
			for (int i = 0; i < 10; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
	}

	void Idle(bool status) {
		if (status == false)
			for (int i = 10; i < 19; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
	}

	bool Duck() {
		if (Keyboard::isKeyPressed(Keyboard::Down)) {
			float tmpy = 420.0f;
			for (int i = 19; i < 34; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos.x, tmpy);
			}
			return true;
		}
		return false;
	}

	bool WalkFront() {
		if (Keyboard::isKeyPressed(Keyboard::Right)) {
			if (pos.x <= 1100.0f)
				pos.x = pos.x + 15;

			for (int i = 34; i < 44; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos.x, pos.y);
			}
			return true;
		}
		return false;
	}

	bool WalkBack(){
		if (Keyboard::isKeyPressed(Keyboard::Left)) {
			if (pos.x > 0.0f)
				pos.x = pos.x - 15;

			for (int i = 44; i < 53; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos.x, pos.y);
			}
			return true;
		}
		return false;
	}

	bool Jump() {
		if (Keyboard::isKeyPressed(Keyboard::Up)) {
			float tmpy = pos.y;
			for(int i=53; i<116; i++){
                sprite[i].setScale(
                    targetSize.x / sprite[i].getLocalBounds().width,
                    targetSize.y / sprite[i].getLocalBounds().height);
                sprite[i].setPosition(pos.x, pos.y);

			}

			return true;
		}
		return false;
	}

	bool Punch() {
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			for (int i = 116; i < 129; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
			return true;
		}
		return false;
	}

	bool Kick() {
		if (Keyboard::isKeyPressed(Keyboard::S)) {
			for (int i = 129; i < 144; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
			return true;
		}
		return false;
	}

	bool Combo() {
		if (Keyboard::isKeyPressed(Keyboard::D)) {
			for (int i = 144; i < 196; i++) {
			sprite[i].setScale(
				targetSize.x / sprite[i].getLocalBounds().width,
				targetSize.y / sprite[i].getLocalBounds().height);
			sprite[i].setPosition(pos);
			}
			return true;
		}
		return false;
	}

	bool Block() {
		if (Keyboard::isKeyPressed(Keyboard::F)) {
			for (int i = 196; i < 207; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
			return true;
		}
		return false;
	}

	bool Dead() {
		if (health <= 0) {
			for (int i = 207; i < 223; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
			return true;
		}
		return false;
	}

	void setPos(Vector2f pos) {
		this->pos = pos;
	}
};
class Ryo:public characters
{

	int health;

	Vector2f targetSize;
	Vector2f pos;
public:
	Ryo(string name = "RYO") :characters(name) {

		texture = new Texture[142];
		sprite = new Sprite[142];
		pos.x = 1100.0f;
		pos.y = 365.0f;

		targetSize.x = 140.0f; // 250
		targetSize.y = 240.0f; // 400
		health = 100;
// ryo ready
        for (int i = 0; i < 27; ++i)
		{
		    int k=0;
			texture[i].loadFromFile("AssetsNew/Ryu/ryuReady/ready (" + to_string(i - k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}
// idle
        for (int i = 27; i < 33; ++i)
		{
		    int k=27;
			texture[i].loadFromFile("AssetsNew/Ryu/ryuIdle/idle (" + to_string(i - k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}
// Duck
        for (int i = 33; i < 51; ++i)
		{
		    int k=33;
			texture[i].loadFromFile("AssetsNew/Ryu/ryuDuck/duck (" + to_string(i - k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}
// Walk Front
        for (int i = 51; i < 59; ++i)
		{
		    int k=51;
			texture[i].loadFromFile("AssetsNew/Ryu/ryuWalkFront/walkFront (" + to_string(i - k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}
// Walk back
        for (int i = 59; i < 67; ++i)
		{
		    int k=59;
			texture[i].loadFromFile("AssetsNew/Ryu/ryuWalkBack/walkBack (" + to_string(i - k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}
// Jump
        for (int i = 67; i < 82; ++i)
		{
		    int k=67;
			texture[i].loadFromFile("AssetsNew/Ryu/ryuJump/jump (" + to_string(i - k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}
// Punch
        for (int i = 82; i < 92; ++i)
		{
		    int k=82;
			texture[i].loadFromFile("AssetsNew/Ryu/ryuPunch/punch (" + to_string(i - k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}
// Kick
        for (int i = 92; i < 101; ++i)
		{
		    int k=92;
			texture[i].loadFromFile("AssetsNew/Ryu/ryuKick/kick (" + to_string(i - k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}
// combo
        for (int i = 101; i < 125; ++i)
		{
		    int k=101;
			texture[i].loadFromFile("AssetsNew/Ryu/ryuCombo/combo (" + to_string(i - k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}
// Block
        for (int i = 125; i < 128; ++i)
		{
		    int k=125;
			texture[i].loadFromFile("AssetsNew/Ryu/ryuBlock/block (" + to_string(i - k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}
// Dead
        for (int i = 128; i < 142; ++i)
		{
		    int k=128;
			texture[i].loadFromFile("AssetsNew/Ryu/ryuDead/dead (" + to_string(i - k + 1) + ").png");
			sprite[i].setTexture(texture[i]);
		}
	}
	~Ryo() {
		health = 0;
	}

	void setHealth(int health) {
		this->health = health;
	}

	int getHealth()const {
		return this->health;
	}

	void Ready(bool status) {
		if (status == true)
			for (int i = 0; i < 27; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
	}

	void Idle(bool status) {
		if (status == false)
			for (int i = 27; i < 33; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
	}

	bool Duck()
	{
		float tmpy = pos.y + 25;
		if (Keyboard::isKeyPressed(Keyboard::K)) {
			for (int i = 33; i < 51; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos.x, tmpy);
			}
			return true;
		}
		return false;
	}

	bool WalkFront() {
		if (Keyboard::isKeyPressed(Keyboard::J)) {
			if (pos.x >= 0.0f )
				pos.x = pos.x - 15;

			for (int i = 51; i < 59; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos.x, pos.y);
			}
			return true;
		}
		return false;
	}

	bool WalkBack() {
		if (Keyboard::isKeyPressed(Keyboard::L)) {
			if (pos.x <= 1100.0f)
				pos.x = pos.x + 15;

			for (int i = 59; i < 67; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos.x, pos.y);

			}
			return true;
		}
		return false;
	}

	bool Jump() {
		if (Keyboard::isKeyPressed(Keyboard::I)) {
			float tmpy = pos.y;
			for(int i=67; i<82; i++){
                sprite[i].setScale(
                    targetSize.x / sprite[i].getLocalBounds().width,
                    targetSize.y / sprite[i].getLocalBounds().height);
                sprite[i].setPosition(pos.x, pos.y);
			}
			return true;
		}
		return false;
	}

	bool Punch() {
		if (Keyboard::isKeyPressed(Keyboard::V)) {
			for (int i = 82; i < 92; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
			return true;
		}
		return false;
	}

	bool Kick() {
		if (Keyboard::isKeyPressed(Keyboard::B)) {
			for (int i = 92; i < 101; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
			return true;
		}
		return false;
	}

	bool Combo() {
		if (Keyboard::isKeyPressed(Keyboard::N)) {
			for (int i = 101; i < 125; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
			return true;
		}
		return false;
	}

	bool Dead() {
		if (health <= 0) {
			for (int i = 128; i < 142; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
			return true;
		}
		return false;
	}

	bool Block() {
		if (Keyboard::isKeyPressed(Keyboard::M)) {
			for (int i = 125; i < 128; i++) {
				sprite[i].setScale(
					targetSize.x / sprite[i].getLocalBounds().width,
					targetSize.y / sprite[i].getLocalBounds().height);
				sprite[i].setPosition(pos);
			}
			return true;
		}
		return false;
	}

	void setPos(Vector2f pos) {
		this->pos = pos;
	}
};
class Level1:public Levels
{

	Font font;
	Text txt[8];

	Iori iori;
	Ryo ryo;
public:
	Level1(string adress = "Assets/background.png",string name = "Level 1") :Levels(adress,name) {
		font.loadFromFile("Assets/COOPBL.ttf");
	}

	~Level1() {
		setTxbg("NULL");
		setName("NULL");
	}


	bool back() {
		if (Keyboard::isKeyPressed(Keyboard::Escape))
			return true;

		return false;
	}
	void draw()
	{

		txt[0].setFont(font);
		txt[0].setString(getName());
		txt[0].setPosition(600.0f, 250.0f);
		txt[0].setColor(Color::Yellow);
		txt[0].setCharacterSize(72);

		txt[1].setFont(font);
		txt[1].setString("Ready!");
		txt[1].setPosition(600.0f, 350.0f);
		txt[1].setColor(Color::Yellow);
		txt[1].setCharacterSize(72);

		txt[2].setFont(font);
		txt[2].setString("IORI");
		txt[2].setPosition(75.0f, 50.0f);
		txt[2].setColor(Color::Yellow);
		txt[2].setCharacterSize(60);

		string str = to_string(iori.getHealth());
		txt[4].setFont(font);
		if (iori.getHealth() <= 0) {
			str = '0';
			txt[4].setColor(Color::Yellow);
		}

		else
			txt[4].setColor(Color::Yellow);

		txt[4].setString(str);
		txt[4].setPosition(75.0f, 0.1f);
		txt[4].setCharacterSize(72);

		txt[3].setFont(font);
		txt[3].setString("RYO");
		txt[3].setPosition(1100.0f, 50.0f);
		txt[3].setColor(Color::Yellow);
		txt[3].setCharacterSize(60);

		string str1 = to_string(ryo.getHealth());
		txt[5].setFont(font);

		if (ryo.getHealth()<=0) {
			str1 = '0';
			txt[5].setColor(Color::Yellow);
		}

		else
			txt[5].setColor(Color::Yellow);

		txt[5].setString(str1);
		txt[5].setPosition(1100.0f, 0.05f);
		txt[5].setCharacterSize(72);

		txt[6].setFont(font);
		txt[6].setString("Iori Wins !");
		txt[6].setPosition(500.0f, 300.0f);
		txt[6].setColor(Color::Yellow);
		txt[6].setCharacterSize(72);

		txt[7].setFont(font);
		txt[7].setString("Ryo Wins !");
		txt[7].setPosition(500.0f, 300.0f);
		txt[7].setColor(Color::Yellow);
		txt[7].setCharacterSize(72);
	}

	Text gettxt(int i) {
		return txt[i];
	}


	void IW_setHealth(int health) {
		iori.setHealth(health);
	}

	int IW_getHealth() {
		return iori.getHealth();
	}

	void IW_Ready(bool status) {
		iori.Ready(status);
	}

	void IW_Idle(bool key) {
		iori.Idle(key);
	}

	bool IW_Duck() {
		return iori.Duck();
	}

	bool IW_WalkFront() {
		return iori.WalkFront();
	}

	bool IW_WalkBack() {
		return iori.WalkBack();
	}

	bool IW_Jump() {
		return iori.Jump();
	}

	bool IW_Punch() {
		return iori.Punch();
	}

	bool IW_Kick() {
		return iori.Kick();
	}

	bool IW_Combo() {
		return iori.Combo();
	}

	bool IW_Block() {
		return iori.Block();
	}

	bool IW_Dead() {
		return iori.Dead();
	}

	Sprite IW_getSprite(int i) {
		return iori.getSprite(i);
	}

	void IW_setPos(Vector2f pos) {
		iori.setPos(pos);
	}


	void RW_setHealth(int health) {
		ryo.setHealth(health);
	}

	int RW_getHealth() {
		return ryo.getHealth();
	}

	void RW_Ready(bool status) {
		ryo.Ready(status);
	}

	void RW_Idle(bool key) {
		ryo.Idle(key);
	}

	bool RW_Duck() {
		return ryo.Duck();
	}

	bool RW_WalkFront() {
		return ryo.WalkFront();
	}

	bool RW_WalkBack() {
		return ryo.WalkBack();
	}

	bool RW_Jump() {
		return ryo.Jump();
	}

	bool RW_Punch() {
		return ryo.Punch();
	}

	bool RW_Kick() {
		return ryo.Kick();
	}

	bool RW_Combo() {
		return ryo.Combo();
	}

	bool RW_Block() {
		return ryo.Block();
	}

	bool RW_Dead() {
		return ryo.Dead();
	}

	Sprite RW_getSprite(int i) {
		return ryo.getSprite(i);
	}

	void RW_setPos(Vector2f pos) {
		ryo.setPos(pos);
	}

	void Game(int ioriPcontroller, int iorikcontroller, int ioriCcontroller,int ryoPcontroller, int ryokcontroller, int ryoCcontroller) {
		if (ryoPcontroller == 91 ) {
				IntRect rect(ryo.getSprite(91).getGlobalBounds());
				IntRect rect1(iori.getSprite(18).getGlobalBounds());
				if (rect.intersects(rect1))
					iori.setHealth(iori.getHealth() - 5);
		}

		else if (ryokcontroller == 100) {
			IntRect rect(ryo.getSprite(100).getGlobalBounds());
			IntRect rect1(iori.getSprite(18).getGlobalBounds());
			if (rect.intersects(rect1))
				iori.setHealth(iori.getHealth() - 5);
		}

		else {
			if (ryoCcontroller == 124) {
				IntRect rect(ryo.getSprite(124).getGlobalBounds());
				IntRect rect1(iori.getSprite(18).getGlobalBounds());
				if (rect.intersects(rect1))
					iori.setHealth(iori.getHealth() - 20);
			}
		}

		if (ioriPcontroller == 128) {
			IntRect rect(iori.getSprite(128).getGlobalBounds());
			IntRect rect1(ryo.getSprite(32).getGlobalBounds());
			if (rect.intersects(rect1))
				ryo.setHealth(ryo.getHealth() - 5);
		}

		else if (iorikcontroller == 143) {
			IntRect rect(iori.getSprite(143).getGlobalBounds());
			IntRect rect1(ryo.getSprite(32).getGlobalBounds());
			if (rect.intersects(rect1))
				ryo.setHealth(ryo.getHealth() - 5);
		}

		else {
			if ((ioriCcontroller == 195)) {
				IntRect rect(iori.getSprite(195).getGlobalBounds());
				IntRect rect1(ryo.getSprite(32).getGlobalBounds());
				if (rect.intersects(rect1))
					ryo.setHealth(ryo.getHealth() - 20);
			}
		}

	}
};
int main() {
	RenderWindow window(VideoMode(800, 640), "Street Fighter!", Style:: Fullscreen);
	window.setFramerateLimit(60);
	mainmenu menu;
	Instruction instructions;
	Level1 lvl1;
	bool iskeyPressed = false, iskeyPressed2 = false, isExit = false, changeLevel = false, f = false;
	int flag = 0, nxtlvl = 0;
	int animationcontroller[11] = { 0, 10, 19, 34, 44, 53, 116, 129, 144, 196, 207};
	int animcontrolller2[11] = { 0, 27, 33, 51, 59, 67, 82, 92, 101, 125, 128};
	Clock clock;
	Music music[8];
	music[0].openFromFile("Assets/sound/Track_01.ogg");
	music[1].openFromFile("Assets/sound/Track_02.ogg");
	music[2].openFromFile("Assets/sound/Track_03.ogg");
	music[3].openFromFile("Assets/sound/Crowd.ogg");
	music[4].openFromFile("Assets/sound/End.ogg");
	music[5].openFromFile("Assets/sound/Kick.ogg");
	music[6].openFromFile("Assets/sound/Punch.ogg");
	music[7].openFromFile("Assets/sound/Start.ogg");
	music[3].play();
	music[3].setLoop(true);
	music[3].setVolume(0);
	while (window.isOpen()) {
		if (music[2].getStatus() == SoundSource::Stopped) {
			music[0].play();
			music[0].setVolume(40);
		}

		if (music[0].getStatus() == SoundSource::Stopped) {
			music[1].play();
			music[1].setVolume(40);
		}

		if (music[1].getStatus() == SoundSource::Stopped) {
			music[2].play();
			music[2].setVolume(40);
		}


		Event event;
		while (window.pollEvent(event)) {
			if (flag == 0) {

				isExit = menu.exit();
				if (isExit)
					window.close();

				changeLevel = menu.instructions();
				if (changeLevel)
					flag = 1;

				changeLevel = menu.play();
				if (changeLevel == true) {
					flag = 2;
					clock.restart();
					animationcontroller[0] = 0;
					animcontrolller2[0] = 0;
					lvl1.IW_setHealth(100);
					lvl1.RW_setHealth(100);
					animcontrolller2[10] = 128;
					animationcontroller[10] = 207;
					Vector2f v(100.0f, 365.0f);
					lvl1.IW_setPos(v);
					v.x = 1100.0f;
					v.y = 365.0f;
					lvl1.RW_setPos(v);
				}
			}

			if (flag == 1) {
				changeLevel = instructions.back();
				if (changeLevel == true)
					flag = 0;
				music[3].setVolume(0);
			}

			if (flag == 2) {
				changeLevel = lvl1.back();
				if (changeLevel == true)
					flag = 0;
			}

			if (event.type == Event::Closed)
				window.close();
		}

		window.clear();
		if (flag == 0) {
			menu.setPosition();
			menu.draw();
			window.draw(menu.getspbg());
			window.draw(menu.gettitle());
			window.draw(menu.getPlay());
			window.draw(menu.getInstruction());
			window.draw(menu.getExit());
		}

		if (flag == 1) {
			instructions.draw();
			instructions.setPosition();
			window.draw(instructions.getspbg());
			for (int i = 0; i < 7; i++)
				window.draw(instructions.getTx(i));
		}
		if (flag == 2) {
			lvl1.setPosition();
			window.draw(lvl1.getspbg());
			lvl1.draw();
			Time t1 = clock.getElapsedTime();
			if (t1.asSeconds() < 2.0f) {
				if (!f) {
					music[7].play();
					music[7].setVolume(100);
					music[3].setVolume(5);
				}

				for (int i = 0; i < 2; i++)
					window.draw(lvl1.gettxt(i));

				lvl1.IW_Ready(true);
				if (animationcontroller[0] >= 0 && animationcontroller[0] <= 9) {
					window.draw(lvl1.IW_getSprite(animationcontroller[0]));
					animationcontroller[0]++;
				}

				else
					window.draw(lvl1.IW_getSprite(animationcontroller[0] - 1));


				lvl1.RW_Ready(true);
				if (animcontrolller2[0] >= 0 && animcontrolller2[0] <= 26) {
					window.draw(lvl1.RW_getSprite(animcontrolller2[0]));
					animcontrolller2[0]++;
				}

				else
					window.draw(lvl1.RW_getSprite(animcontrolller2[0] - 1));

				f = true;
			}

			for (int i = 2; i < 6; i++)
				window.draw(lvl1.gettxt(i));

			if (t1.asSeconds() > 2.0f) {
				music[3].setVolume(100);
				if (lvl1.RW_getHealth() > 0 && lvl1.IW_getHealth() > 0) {
					lvl1.Game(animationcontroller[6], animationcontroller[7], animationcontroller[8], animcontrolller2[6], animcontrolller2[7], animcontrolller2[8]);

					if (iskeyPressed == false) {
						lvl1.IW_Idle(iskeyPressed);
						if (animationcontroller[1] >= 10 && animationcontroller[1] <= 18) {
							window.draw(lvl1.IW_getSprite(animationcontroller[1]));
							animationcontroller[1]++;
						}
						else {
							window.draw(lvl1.IW_getSprite(animationcontroller[1] - 1));
							animationcontroller[1] = 10;
						}
					}

					if (lvl1.IW_Duck() == true) {
						iskeyPressed = true;
						if (animationcontroller[2] >= 19 && animationcontroller[2] < 34) {
							window.draw(lvl1.IW_getSprite(animationcontroller[2]));
							animationcontroller[2]++;
						}
						else {
							window.draw(lvl1.IW_getSprite(animationcontroller[2] - 1));
							animationcontroller[2] = 19;
						}
					}

					else if (lvl1.IW_WalkFront() == true) {
						iskeyPressed = true;
						if (animationcontroller[3] >= 34 && animationcontroller[3] < 44) {
							window.draw(lvl1.IW_getSprite(animationcontroller[3]));
							animationcontroller[3]++;
						}
						else {
							window.draw(lvl1.IW_getSprite(animationcontroller[3] - 1));
							animationcontroller[3] = 34;
						}
					}

					else if (lvl1.IW_WalkBack() == true) {
						iskeyPressed = true;
						if (animationcontroller[4] >= 44 && animationcontroller[4] < 53) {
							window.draw(lvl1.IW_getSprite(animationcontroller[4]));
							animationcontroller[4]++;
						}
						else {
							window.draw(lvl1.IW_getSprite(animationcontroller[4] - 1));
							animationcontroller[4] = 44;
						}
					}

					else if (lvl1.IW_Jump() == true) {
						iskeyPressed = true;
						if (animationcontroller[5] >= 53 && animationcontroller[5] <= 115) {
							window.draw(lvl1.IW_getSprite(animationcontroller[5]));
							animationcontroller[5]++;
						}
						else {
							window.draw(lvl1.IW_getSprite(animationcontroller[5] - 1));
							animationcontroller[5] = 53;
						}
					}

					else if (lvl1.IW_Punch() == true) {
						music[6].play();
						music[6].setVolume(100);
						iskeyPressed = true;
						if (animationcontroller[6] >= 116 && animationcontroller[6] <= 128) {
							window.draw(lvl1.IW_getSprite(animationcontroller[6]));
							animationcontroller[6]++;
						}
						else {
							window.draw(lvl1.IW_getSprite(animationcontroller[6] - 1));
							animationcontroller[6] = 116;
						}
					}

					else if (lvl1.IW_Kick() == true) {
						music[5].play();
						music[5].setVolume(100);
						iskeyPressed = true;
						if (animationcontroller[7] >= 129 && animationcontroller[7] <= 143) {
							window.draw(lvl1.IW_getSprite(animationcontroller[7]));
							animationcontroller[7]++;
						}
						else {
							window.draw(lvl1.IW_getSprite(animationcontroller[7] - 1));
							animationcontroller[7] = 129;
						}
					}

					else if (lvl1.IW_Combo() == true) {
						iskeyPressed = true;
						if (animationcontroller[8] >= 144 && animationcontroller[8] <= 195)
						{
							window.draw(lvl1.IW_getSprite(animationcontroller[8]));
							animationcontroller[8]++;
						}
						else
						{
							window.draw(lvl1.IW_getSprite(animationcontroller[8] - 1));
							animationcontroller[8] = 144;
						}
					}

					else if (lvl1.IW_Block() == true) {
						iskeyPressed = true;
						if (animationcontroller[9] >= 196 && animationcontroller[9] < 207) {
							window.draw(lvl1.IW_getSprite(animationcontroller[9]));
							animationcontroller[9]++;
						}
						else {
							window.draw(lvl1.IW_getSprite(animationcontroller[9] - 1));
							animationcontroller[9] = 196;
						}
					}

					else if (lvl1.IW_Dead() == true) {
						iskeyPressed = true;
						if (animationcontroller[10] >= 207 && animationcontroller[10] < 223) {
							window.draw(lvl1.IW_getSprite(animationcontroller[10]));
							animationcontroller[10]++;
							Sleep(100);
						}
						else
							window.draw(lvl1.IW_getSprite(animationcontroller[10]));
					}
					else
						iskeyPressed = false;

					if (iskeyPressed2 == false) {
						lvl1.RW_Idle(iskeyPressed2);
						if (animcontrolller2[1] >= 27 && animcontrolller2[1] <= 32) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[1]));
							animcontrolller2[1]++;
						}
						else {
							window.draw(lvl1.RW_getSprite(animcontrolller2[1] - 1));
							animcontrolller2[1] = 27;
						}
					}

					if (lvl1.RW_Duck() == true) {
						iskeyPressed2 = true;
						if (animcontrolller2[2] >= 33 && animcontrolller2[2] <50) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[2]));
							animcontrolller2[2]++;
						}
						else {
							window.draw(lvl1.RW_getSprite(animcontrolller2[2] - 1));
							animcontrolller2[2] = 33;
						}
					}

					else if (lvl1.RW_WalkFront() == true) {
						iskeyPressed2 = true;
						if (animcontrolller2[3] >= 51 && animcontrolller2[3] < 59) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[3]));
							animcontrolller2[3]++;
						}
						else {
							window.draw(lvl1.RW_getSprite(animcontrolller2[3] - 1));
							animcontrolller2[3] = 51;
						}
					}

					else if (lvl1.RW_WalkBack() == true) {
						iskeyPressed2 = true;
						if (animcontrolller2[4] >= 59 && animcontrolller2[4] <= 66) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[4]));
							animcontrolller2[4]++;
						}
						else {
							window.draw(lvl1.RW_getSprite(animcontrolller2[4] - 1));
							animcontrolller2[4] = 59;
						}
					}

					else if (lvl1.RW_Jump() == true) {
						iskeyPressed2 = true;
						if (animcontrolller2[5] >= 67 && animcontrolller2[5] <= 82) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[5]));
							animcontrolller2[5]++;
						}
						else {
							window.draw(lvl1.RW_getSprite(animcontrolller2[5] - 1));
							animcontrolller2[5] = 67;
						}
					}

					else if (lvl1.RW_Punch() == true) {
						music[6].play();
						music[6].setVolume(100);
						iskeyPressed2 = true;
						if (animcontrolller2[6] >= 82 && animcontrolller2[6] <= 91) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[6]));
							animcontrolller2[6]++;
						}
						else {
							window.draw(lvl1.RW_getSprite(animcontrolller2[6] - 1));
							animcontrolller2[6] = 82;
						}

					}

					else if (lvl1.RW_Kick() == true) {
						music[5].play();
						music[5].setVolume(100);
						iskeyPressed2 = true;
						if (animcontrolller2[7] >= 92 && animcontrolller2[7] <= 101) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[7]));
							animcontrolller2[7]++;
						}
						else {
							window.draw(lvl1.RW_getSprite(animcontrolller2[7] - 1));
							animcontrolller2[7] = 92;
						}

					}

					else if (lvl1.RW_Combo() == true) {
						iskeyPressed2 = true;
						if (animcontrolller2[8] >= 101 && animcontrolller2[8] <= 124) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[8]));
							animcontrolller2[8]++;
						}
						else {
							window.draw(lvl1.RW_getSprite(animcontrolller2[8] - 1));
							animcontrolller2[8] = 101;
						}
					}

					else if (lvl1.RW_Block() == true) {
						iskeyPressed2 = true;
						if (animcontrolller2[9] >= 125 && animcontrolller2[9] < 128) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[9]));
							animcontrolller2[9]++;
						}
						else {
							window.draw(lvl1.RW_getSprite(animcontrolller2[9] - 1));
							animcontrolller2[9] = 125;
						}
					}

					else if (lvl1.RW_Dead() == true) {
						iskeyPressed2 = true;
						if (animcontrolller2[10] >= 128 && animcontrolller2[10] < 142) {
							window.draw(lvl1.RW_getSprite(animcontrolller2[10]));
							animcontrolller2[10]++;
							Sleep(70);
						}
						else
							window.draw(lvl1.RW_getSprite(animcontrolller2[10]));
					}
					else {
						iskeyPressed2 = false;
						f = false;
					}
				}
				else {
					lvl1.draw();
					if (!f) {
						music[3].setVolume(20);
						music[4].play();
						music[4].setVolume(100);
					}
					if (lvl1.IW_getHealth() <= 0) {
						window.draw(lvl1.gettxt(7));
						window.draw(lvl1.RW_getSprite(6));
					}
					else {
						window.draw(lvl1.gettxt(6));
						window.draw(lvl1.IW_getSprite(3));
					}
					f = true;
				}
			}
		}
		window.display();
		Sleep(50);
	}
	return 0;
}
