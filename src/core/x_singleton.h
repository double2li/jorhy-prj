#ifndef __SINGLETON_H_
#define __SINGLETON_H_

template <typename CBase>
class SingletonTmpl
{
private:
	struct object_creator  
	{  
		object_creator()   
		{  
			SingletonTmpl<CBase>::Instance();   
		}  
		inline void do_nothing() const {}  
	};  
	//������ľ�̬����object_creator�Ĺ����ʼ��,�ڽ���main֮ǰ�Ѿ�������instance  
	//�Ӷ������˶�γ�ʼ��������  
	static object_creator create_object_;
public:
	static CBase *Instance()
	{
		static CBase obj;  
		//do_nothing �Ǳ�Ҫ�ģ�do_nothing�������е���˼��  
		//�������create_object_.do_nothing();��仰����main����ǰ��  
		//create_object_�Ĺ��캯�������ᱻ���ã�instance��ȻҲ���ᱻ���ã�  
		//�ҵĹ�����ģ����ӳ�ʵ�ֵ���Ч���£����û����仰��������Ҳ����ʵ��  
		// SingletonTmpl<CBase>::object_creator,���Ծͻᵼ���������  
		create_object_.do_nothing();  
		return &obj; 
	}
};

template <typename CBase>
typename SingletonTmpl<CBase>::object_creator SingletonTmpl<CBase>::create_object_;

#endif //~__SINGLETON_H_
