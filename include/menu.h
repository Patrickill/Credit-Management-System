
#include<iostream>

class menu{
public:

    void display_begin(){
        std::cout<<"---------------------------��ӭʹ��ѧ�ֹ���ϵͳ----------------------------------"<<std::endl;
        std::cout<<"���벻ͬ���ֵ�½��ͬ�û�:"<<std::endl;
        std::cout<<"0:�˳�ϵͳ"<<std::endl;
        std::cout<<"1:ѧ��"<<std::endl;
        std::cout<<"2:��ʦ"<<std::endl;
        std::cout<<">";
    }

    bool display_welcome_student(){
        std::cout<<"---------------------------���ͬѧ,��ӭʹ��ѧ�ֹ���ϵͳ----------------------------------"<<std::endl;
        std::cout<<"���벻ͬ���ֽ��벻ͬģʽ:"<<std::endl;
        std::cout<<"0:�˳�ϵͳ"<<std::endl;
        std::cout<<"1:��ѯģʽ"<<std::endl;
        std::cout<<"2:����ģʽ"<<std::endl;
        std::cout<<">";
        return true;
    }

    bool display_welcome_admin(){
        std::cout<<"---------------------------�����ʦ,��ӭʹ��ѧ�ֹ���ϵͳ----------------------------------"<<std::endl;
        std::cout<<"���벻ͬ���ֽ��벻ͬģʽ:"<<std::endl;
        std::cout<<"0:�˳�ϵͳ"<<std::endl;
        std::cout<<"1:��ѯģʽ"<<std::endl;
        std::cout<<"2:����ģʽ"<<std::endl;
        std::cout<<"3:�༭ģʽ"<<std::endl;
        std::cout<<">";
        return true;
    }

    void display_consult(){
        std::cout<<"--------------------------------------��ѯģʽ---------------------------------"<<std::endl;
        std::cout<<"0:�˳�ģʽ"<<std::endl;
        std::cout<<"1:��ѧ�Ų�ѯѧ��������\"1 ѧ��\"��( 1 114514)"<<std::endl;
        std::cout<<"2:���༶����ð༶ȫ��ѧ����������\"2 �༶\"��(2 5)"<<std::endl;
        std::cout<<">";
    }

    bool display_change(){
        std::cout<<"--------------------------------------�༭ģʽ---------------------------------"<<std::endl;
        std::cout<<"0:�˳�ģʽ"<<std::endl;
        std::cout<<"1:���ѧ�� ����(1 ���� ѧ�� �༶ ������ѧ�� רҵ��ѧ�� ѡ�޿�ѧ�� ������ѧ�� ʵ���Կγ�ѧ��)���ѧ��"<<std::endl;
        std::cout<<"2:ɾ��ѧ�� ����(2 ��������ѧ��)����ɾ����ѧ��"<<std::endl;
        std::cout<<"3:�޸�ѧ��ѧ�� ����(3 ��������ѧ��)��ȷ��ѧ����Ϣ��������(������ѧ�� רҵ��ѧ�� ѡ�޿�ѧ�� ������ѧ�� ʵ���Կγ�ѧ��)�޸�ѧ������"<<std::endl;
        std::cout<<">";
        return true;
    }

    bool display_sort(){
        std::cout<<"-----------------------------------����ģʽ------------------------------------"<<std::endl;
        std::cout<<"0:�˳�ģʽ"<<std::endl;
        std::cout<<"1: �������� "<<std::endl;
        std::cout<<"2: �������� "<<std::endl;
        std::cout<<"������������1-5�ֱ��Ӧ ������ѧ�� רҵ��ѧ�� ѡ�޿�ѧ�� ������ѧ�� ʵ���Կγ�ѧ�� ��(1 1 ��ʾ�Ի�����ѧ�ֽ�������)"<<std::endl;
        std::cout<<">";
        return true;
    }

};
