// Super Market Project with OOPS
#include<iostream>
#include<string.h>
using namespace std;

struct Items_List
{
	int icode,qty;
	float price,amount;
	char iname[20];
}items[100];  // means 100 items you are able sell

float tamount=0;
int i=0,icount=0;

class SuperMarket
{
	public:
		// AddItem is a method used to add new Item to Bill
		void AddItem()
		{
			cout<<"\n enter item code:";
			cin>>items[i].icode;
			cout<<"\n enter item name:";
			cin>>items[i].iname;
			cout<<"\n enter price :";
			cin>>items[i].price;
			cout<<"\n enter quantity :";
			cin>>items[i].qty;
			items[i].amount=items[i].qty*items[i].price;
			i++;
			icount++;
		}

// UpdateBill is a method used to Modify Quantity or to delete Items from Bill
		void UpdateBill()
		{
			int ch,ticode,tqty,status;

			cout<<" 1. Modify Quantity "<<endl;
			cout<<" 2. Delete Item     "<<endl;
			cout<<"\n enter your choice :";
			cin>>ch;
			switch(ch)
			{
				case 1:

					cout<<"\n enter item code:";
					cin>>ticode;
					cout<<"\n enter new quantity:";
					cin>>tqty;
				    status=0;
				for(int j=0;j<icount;j++)
				{
			   		if(items[j].icode==ticode)
			   		{
			   	   	items[j].qty=tqty;
		  		items[j].amount=items[j].qty*items[j].price;
			   	   	status=1;
			   	   	break;
			  	    }
				}
				if(status==1)
				cout<<"\n Quantity Updated Successfully"<<endl;
				else
				cout<<"\n Item is not found with this id...!!!";

					break;
				case 2:
					cout<<"\n enter item code:";
					cin>>ticode;
					status=0;
					for(int j=0;j<icount;j++)
					{
					   if(items[j].icode==ticode)
			   			{
			   	   		items[j].qty=0;
			  items[j].amount=items[j].qty*items[j].price;
			   	strcpy(items[j].iname," ");
			   	   	status=1;
			   	   		break;
			   			}
					}
					if(status==1)
					cout<<"\n Item Deleted Successfully";
					else
			cout<<"\n Item is not found with this id...!!!";

						break;
				default:cout<<"\n Invalid choice...!";

			}


		}

		// ShowBill Method is used to View Bill
		void ShowBill()
		{
			int tamount=0;
			cout<<"\nIcode"<<"\t"<<"ItemName\t"<<"Price"<<"\t"<<"Qty"<<"\tAmount"<<endl;
			cout<<"\n====================================================="<<endl;
			for(int i=0;i<icount && items[i].amount!=0;i++)
			{
			cout<<"\n"<<items[i].icode<<"\t"<<items[i].iname<<"\t\t"<<items[i].price<<"\t"<<items[i].qty<<"\t"<<items[i].amount;
			tamount=tamount+items[i].amount;
			}
			cout<<"\n==============================================";
			cout<<"\n\n Total Bill Amount:"<<tamount;
		}
};	// end of the class

main()
{
	SuperMarket sm;
	while(1)
	{
		cout<<"\n 1. Add Item ";
		cout<<"\n 2. Update Bill";
		cout<<"\n 3. Show Bill";
		cout<<"\n 4. Exit";
		cout<<"\n enter your choice :";
		int ch;
		cin>>ch;
		switch(ch)
		{
			case 1:sm.AddItem();break;
			case 2:sm.UpdateBill();break;
			case 3:sm.ShowBill();break;
			case 4:exit(0);
			default:cout<<"\n Invalid choice...!";
		}
	}// while close
} // main
