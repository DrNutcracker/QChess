#include "QuantumPiece.h"

using namespace Logic;

QuantumPiece::QuantumPiece(int pType, int sType, int r, int c)
{
	primaryType = pType;
	secondaryType = sType;
	currentType = SUPER_POSITION;
	row = r;
	col = c;

	if (primaryType == KING)//make a special case for the king, since it is never in a q-state
	{
		currentType = KING;
	}
}

QuantumPiece::~QuantumPiece(){}
void QuantumPiece::update(float deltaTime){}

void QuantumPiece::draw()
{
	//need to call the draw method of corresponding model(s)
	if (currentType == SUPER_POSITION)
	{
		//do some weird phasey thing with both mdoels
	}
	else if (currentType == primaryType)
	{
		//draw primary model
	}
	else
	{
		//draw secondary model
	}
}

void QuantumPiece::setPosition(int r, int c)
{
	row = r;
	col = c;
}

int QuantumPiece::getRow()
{
	return row;
}

int QuantumPiece::getCol()
{
	return col;
}

bool QuantumPiece::isInSuperPosition()
{
	if (currentType == SUPER_POSITION)
		return true;
	return false;
}

int QuantumPiece::getType()
{
	if (currentType == SUPER_POSITION)//if not in superposition, don't reset state
	{
		if (rand() % 2 == 0)
			currentType = primaryType;
		else
			currentType = secondaryType;
	}
	return currentType;
}

void QuantumPiece::setPrimaryType(int type)
{
	primaryType = type;
}

void QuantumPiece::setSecondaryType(int type)
{
	secondaryType = type;
}

void QuantumPiece::setSuperPosition(bool isQ)
{
	if (currentType == SUPER_POSITION && !isQ) //if in superposition and should be in classical state, collapse
	{
		getType();
	}
	if (currentType != SUPER_POSITION && isQ) //if NOT in superposition and should be in quantum state, lose identity
	{
		currentType = SUPER_POSITION;
	}
}