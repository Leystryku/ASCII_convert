#include "ASCII_convert.h"


bool bToAscii;

int ClearInput()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return 1;
}

std::string hextobin(std::string sHex)
{
	std::string sRet = "";
	int iHexLen = sHex.length();

	for (int i = 0; i < iHexLen; ++i)
	{
		switch (tolower(sHex[i]))
		{
			case '0': sRet.append("0000"); break;
			case '1': sRet.append("0001"); break;
			case '2': sRet.append("0010"); break;
			case '3': sRet.append("0011"); break;
			case '4': sRet.append("0100"); break;
			case '5': sRet.append("0101"); break;
			case '6': sRet.append("0110"); break;
			case '7': sRet.append("0111"); break;
			case '8': sRet.append("1000"); break;
			case '9': sRet.append("1001"); break;
			case 'a': sRet.append("1010"); break;
			case 'b': sRet.append("1011"); break;
			case 'c': sRet.append("1100"); break;
			case 'd': sRet.append("1101"); break;
			case 'e': sRet.append("1110"); break;
			case 'f': sRet.append("1111"); break;
		}
	}

	return sRet;
}

std::vector<std::string> split( const std::string sToSplit, char cDelimiter )
{
	std::vector<std::string> elems;
	std::stringstream ssToSplit(sToSplit);
	std::string sItem;

	while (std::getline(ssToSplit, sItem, cDelimiter))
		elems.push_back(sItem);

	return elems;
}

int convert_toascii( std::string sToConvert )
{

	std::cout << std::endl;

	std::stringstream ssDec, ssHex, ssBinary, ssASCII;

	//dec->hex->binary->ascii

	std::vector<std::string> vSplitString = split(sToConvert, ' ');

	for (std::vector<std::string>::iterator it = vSplitString.begin(); it != vSplitString.end(); ++it)
	{
		int iToConvert = atoi(it->c_str());

		if (iToConvert > 127 || iToConvert < 0)
		{
			iToConvert = 63;
		}

		ssDec << iToConvert << " ";

		std::stringstream ssHexChar, ssBinaryChar;
		ssHexChar << std::hex << iToConvert;
		ssHex << ssHexChar.str() << " ";


		ssBinaryChar << hextobin(ssHexChar.str());

		std::bitset<8> bBin(ssBinaryChar.str());
		ssBinary << "[0]" << bBin.to_string().erase(0, 1) << " ";

		if (iToConvert > 31 && iToConvert != 127)
		{
			ssASCII << (char)bBin.to_ulong();
		}
	}

	std::cout << "Dec: " << ssDec.str() << std::endl << std::endl;
	std::cout << "Hex: " << ssHex.str() << std::endl << std::endl;
	std::cout << "Binary: " << ssBinary.str() << std::endl << std::endl;
	std::cout << "ASCII: " << ssASCII.str() << std::endl;

	std::cin.get();

	return 1;
}

int printascii( std::string sToPrint )
{
	std::cout << std::endl;

	std::stringstream ssBinary, ssHex, ssDec;

	//ascii->bin->hex->dec

	int iLen = sToPrint.length();

	for (int i = 0; iLen > i; i++)
	{
		if (sToPrint[i] > 127 || sToPrint[i] < 0)
		{
			sToPrint[i] = '?';
		}

		std::bitset<7> bBin(sToPrint[i]);

		ssBinary << "[0]" << bBin << " ";


		std::stringstream hexChar;
		hexChar << std::hex << bBin.to_ulong();
		
		ssHex << hexChar.str() << " ";


		int iDec = 0;

		sscanf(hexChar.str().c_str(), "%x", &iDec);

		ssDec << iDec << " ";
	}

	std::cout << "ASCII: " << sToPrint << std::endl << std::endl;
	std::cout << "Binary: " << ssBinary.str() << std::endl << std::endl;
	std::cout << "Hex: " << ssHex.str() << std::endl << std::endl;
	std::cout << "Decimal: " << ssDec.str() << std::endl << std::endl;

	std::cin.get();
		
	return 1;
}


int ASCII_convert()
{
	//Selection one
	std::cout << "Welcome to Leystryku's ASCII Converter" << std::endl;
	std::cout << "What do you want to do?" << std::endl;

	std::cout << "1. Convert Dec to ASCII" << std::endl;
	std::cout << "2. Convert ASCII to Bin->Hex->Dec" << std::endl;

	char cConvertLine[255];
	int iSelection = std::cin.get();

	switch (iSelection)
	{
		case '1':
			{
				bToAscii = true;
				std::cout << "Converting Dec to ASCII" << std::endl;
				break;
			}
		case '2':
			{
				bToAscii = false;
				std::cout << "Converting ASCII to Bin->Hex->Dec" << std::endl;
				break;
			}
		default:
			{
				ClearInput();
				std::cout << "Invalid input!\a" << std::endl;
				return ASCII_convert();
			}
	}

	ClearInput();
	std::cout << "Please enter the string..." << std::endl;

	if (std::cin.getline(cConvertLine, 255))
		return bToAscii ? convert_toascii(cConvertLine) : printascii(cConvertLine);

	ClearInput();
	std::cout << "Invalid input!\a" << std::endl;

	return ASCII_convert();
}

int main()
{
	return ASCII_convert();
}