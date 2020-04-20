
#include "ListaLekow.h"

void Listalekow::dodajlekdolisty(Lek* lek,Listalekow*& pHead)
{
	if (pHead!= NULL)
	{
		Listalekow * nowyPhead = pHead;
		while (nowyPhead->pNext!= NULL)
		{
			nowyPhead = nowyPhead->pNext;

		}
		Listalekow * nowy = new Listalekow(NULL, lek);
		nowyPhead->pNext = nowy;
		pHead->rozmiar++;

	}
	else
	{
		pHead = new Listalekow(NULL, lek);
		pHead->rozmiar++;
	}
		

}


Listalekow::Listalekow(Listalekow  *listalekow, Lek* lek)
{
	this->pNext = listalekow;
	this->lek = lek;
}

Listalekow::Listalekow()
{
	this->pNext = NULL;
	
}

Listalekow::~Listalekow()
{
	while (pNext) {
		Listalekow* przechowywatorglowy = pNext->pNext;
		delete pNext->lek;
		delete pNext;
		pNext = przechowywatorglowy;

	}
	
}

void Listalekow::usunlekponazwie(string nazwaleku, Listalekow*& pHead)
{
	
	if (pHead)
	{
		if (pHead->lek->getNazwaleku() == nazwaleku)
		{	
			Listalekow* przechowywatorglowy = pHead;
			 pHead = pHead->pNext;
				delete przechowywatorglowy;
				return;
		}

		Listalekow * przechowywatorglowy = pHead;
		while (przechowywatorglowy->pNext->lek->getNazwaleku() != nazwaleku)
		{
			przechowywatorglowy = przechowywatorglowy->pNext;
			if (przechowywatorglowy == nullptr)
			{
				cout << "lek nie znajduje sie aktualnie w liscie";
				return;
			}
			


        }
		Listalekow * wsk = przechowywatorglowy->pNext->pNext;
		delete przechowywatorglowy->pNext;
		przechowywatorglowy->pNext = wsk;



	}
	else
	{
		cout << " Nie ma takiego leku ";
	}



}

void Listalekow::wyczyscliste(Listalekow *& pHead)
{
	delete pHead;
	//Listalekow* przechowywatorglowy = pHead->pNext;
	//while (przechowywatorglowy) {
	//	
	//	delete pHead->lek;
	//	delete pHead;
	//	pHead = przechowywatorglowy;
	//	przechowywatorglowy = pHead->pNext;

	//}


}

Lek Listalekow::znajdzLekPoNazwie(Listalekow *& pHead, string nazwaleku)
{
	Listalekow* przechowywatorglowy = pHead;
	while (przechowywatorglowy->pNext != NULL) {
		if (przechowywatorglowy->lek->getNazwaleku() == nazwaleku) {
			return Lek(przechowywatorglowy->lek->getNazwaleku(), przechowywatorglowy->lek->getRodzajleku(), przechowywatorglowy->lek->getRefundacja(), przechowywatorglowy->lek->getCena(),
				przechowywatorglowy->lek->getOgraniczenia(), przechowywatorglowy->lek->getNumerserii(), przechowywatorglowy->lek->getIloscsztuk());
		}
	}
	cout << "Nie znaleziono takiego leku w liscie";
	return Lek();
}

