#include<iostream>
using namespace std;

class xml
{
    string data;
    
    public:
        xml(string arg)
        {
            this->data = arg;
        }
        
        string getXmlData()
        {
            return data;
        }
};

class analytics
{
    string json;
    public :
        analytics(){}
        
        void setJsonData( string json )
        {
            this->json = json;
        }
        
        virtual void analyseData()
        {
            cout<<"analysing "<<json<<" data"<<endl;
        }
};

class adapter : public analytics
{
    xml *xmlData;
    public:
        adapter( xml *ptr )
        {
            xmlData = ptr;
        }
        
        void analyseData() override
        {
            cout<<"converting xml data -> "<<xmlData->getXmlData()<<" -> to json"<<endl;
            cout<<"coverted to json data"<<endl;
            analytics::setJsonData("{This is xml}");
            analytics::analyseData();
        }
};

class client
{
    public :
        void processData( analytics *tool )
        {
            tool->analyseData();
        }
};

int main()
{
    xml *xObj = new xml("This is xml");
    analytics *tool = new adapter(xObj);
    client *clientObj = new client();
    clientObj->processData( tool );
}
