#include "ASCII_convert.h"


bool bToAscii;
int iConvertFrom = 0; // 1 = dec, 2 = hex, 3 = bin

int ClearInput()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return 1;
}

int convert_toascii(int iType, char *cToConvert)
{

	std::cout << std::endl;

	std::stringstream ssResult;

	if (iType == 1)
	{
		cToConvert = strtok(cToConvert, " ");

		while (cToConvert != NULL)
		{
			int iToConvert = atoi(cToConvert);

			if (iToConvert > 127)
			{
				ssResult << "?";  // not valid ASCII, replace it with '?'
			}else{
				ssResult << (char)iToConvert;
			}
			
			cToConvert = strtok(NULL, " ");
		}

		return printascii(const_cast<char*>(ssResult.str().c_str()));
	}

	if (iType == 2)
	{
		cToConvert = strtok(cToConvert, " ");

		std::stringstream ssHexBuf;

		while (cToConvert != NULL)
		{

			int num = 0;
				
			std::stringstream ssHexBuf;
			ssHexBuf << std::hex << cToConvert;
			ssHexBuf >> num;

			if (num > 127 || num < 0)
			{ 
				ssResult << "?";  // not valid ASCII, replace it with '?'
				continue;
			}

			ssResult << (char)num;

			cToConvert = strtok(NULL, " ");
		}

		return printascii(const_cast<char*>(ssResult.str().c_str()));
	}

	if (iType == 3)
	{
		cToConvert = strtok(cToConvert, " ");

		while (cToConvert != NULL)
		{

			std::bitset <7> bin(cToConvert); // no need to replace invalid chars with '?', it's capped@7 bits
			int iNum = (int)bin.to_ulong();

			ssResult << (char)iNum;

			cToConvert = strtok(NULL, " ");
		}

		
		return printascii(const_cast<char*>(ssResult.str().c_str()));
	}

	return 0;
}

int printascii( char *cToPrint )
{
	std::cout << std::endl;

	std::stringstream ssBinary, ssHex, ssDec;

	int iLen = strlen(cToPrint);

	for (int i = 0; iLen > i; i++)
	{
		if ((int)cToPrint[i] > 127 || (int)cToPrint[i] < 0)
		{
			cToPrint[i] = '?'; // not valid ASCII, replace it with '?'
		}

		std::bitset<7> bBin((int)cToPrint[i]);

		ssBinary << bBin << " ";
	}

	for (int i = 0; iLen > i; i++)
	{
		ssHex << std::hex << (int)cToPrint[i] << " ";
	}

	for (int i = 0; iLen > i; i++)
	{
		ssDec << std::dec << (int)cToPrint[i] << " ";
	}

	std::cout << "Binary: " << ssBinary.str() << std::endl << std::endl;
	std::cout << "Hex: " << ssHex.str() << std::endl << std::endl;
	std::cout << "Decimal: " << ssDec.str() << std::endl << std::endl;
	std::cout << "ASCII: " << cToPrint << std::endl;

	std::cin.get();
		
	return 1;
}


int ASCII_convert()
{
	bToAscii = false;
	iConvertFrom = 0;

	//Selection one
	std::cout << "Welcome to Leystryku's ASCII Converter" << std::endl;
	std::cout << "What do you want to do?" << std::endl;

	std::cout << "1. Convert to ASCII" << std::endl;
	std::cout << "2. Convert from ASCII" << std::endl;

	char cConvertLine[255];
	int iSelection = std::cin.get();

	switch (iSelection)
	{
		case '1':
			{
			bToAscii = true;
			std::cout << "What should I convert to ASCII?" << std::endl;
			break;
			}
		case '2':
			{
			std::cout << "Convert from ASCII:" << std::endl;
			break;
			}
		default:
			{
				ClearInput();
				std::cout << "Invalid input!\a" << std::endl;
				return ASCII_convert();
			}
	}

	if (bToAscii)
	{
		std::cout << "1. Dec" << std::endl;
		std::cout << "2. Hex" << std::endl;
		std::cout << "3. Binary" << std::endl;

	}else{
		ClearInput();
		std::cout << "Please enter the string..." << std::endl;

		if (std::cin.getline(cConvertLine, 255))
		{
			return printascii(cConvertLine);
		}
			
		ClearInput();
		std::cout << "Invalid input!\a" << std::endl;
		return ASCII_convert();
		

	}

	std::cin >> iSelection;

	if (iSelection && iSelection < 4)
	{
		iConvertFrom = iSelection;
	}else{

		ClearInput();
		std::cout << "Invalid input!\a" << std::endl;
		return ASCII_convert();
	}

	std::cout << "Please enter the encoded value..." << std::endl;

	ClearInput();

	if (std::cin.getline(cConvertLine, 255))
	{
		return convert_toascii(iConvertFrom, cConvertLine);
	}else{

		ClearInput();
		std::cout << "Invalid input!\a" << std::endl;
		return ASCII_convert();
	}

	return 0;
}

int main()
{
	return ASCII_convert();
}

