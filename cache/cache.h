#pragma once
#include <string>
#include <deque>
#include <sstream>
#include <fstream>
using namespace std;
template <class T>//Ҫ����==  =(liangge)  !=  < >�����     ������һ����       T=-1Ҫ���سɱ�Ǵε�Ԫ������-
class voxels {//�������ֻ�ṩ�������� getCode��saveOne   ����������Ϊprivate
private:
	string address;
	int levelL, levelH;
public://������sizeҪС�ڵ���levelL������һ���ļ��е���Ŀ    �����м���һ�����  ������� �͸�С   û�м���� ��Ҳ��֪��Ϊʲô  �����ǲ���ʱ��ֻ��һ���ļ�  �ڶ����ļ��򲻿��ͳ�����  ���ļ�����ʱ��Ҫע��
	deque<T> voxel;
	voxels(string address_, int levelL_, int levelH_, int size = 4096);//���캯����Ҫ֪��ȥ������ļ�(Ŀ¼)����ֵ��address  ���Ҷ���ǰsize��ֵ    ������address��deque�Ĵ�С,�����������ִ���   
	typename deque<T>::iterator getCode(unsigned long long mortonCode);//����deque����������Ĵ���  ����з����������  ���û�о�ȥ��һ��
	typename deque<T>::iterator readOneCode(T needed);//����Ϊ��Ҫ��   �������һ�������� ���û���ҵ��ͷ���end()
	typename deque<T>::iterator readOneToUpdate(unsigned long long lordCommander);//����Ϊ��Ҫ����  ��һ��ɾ��һ��  ɾ��ʱ��Ҫ���ļ��еĽ����޸�  ���ض�������ݵĵ�����
	T readOneFromFile(unsigned long long monica);//����monica��ŵ�����
	void saveOne(T oneToSave);//���������������  ������Ӧ�������  û�еĻ��ᱬը
	~voxels() {}
};




template<class T>
inline void voxels<T>::saveOne(T oneToSave) {
	typename deque<T>::iterator temp = readOneCode(oneToSave);
	*temp = oneTosave;
}
template<class T>
inline T voxels<T>::readOneFromFile(unsigned long long monica) {//ʹ�ö��ַ������ļ��е�monica
	string fileAddress;
	unsigned long long fileNum = monica / (1 << (3 * levelL));
	stringstream ss;
	ss << fileNum;
	ss >> fileAddress;
	fileAddress = address + "\\outOfCore" + fileAddress + ".bat";
	ifstream readIn;
	readIn.open(fileAddress, ios::in | ios::binary);
	T majnun;
	readIn.read((char *)&majnun, sizeof(T));
	readIn.seekg(sizeof(T)*monica, ios::beg);
	
	readIn.read((char *)&majnun, sizeof(T));
	
	readIn.close();
	return majnun;
}
template<class T>
inline typename deque<T>::iterator voxels<T>::readOneToUpdate(unsigned long long lordCommander) {
	T majnun = readOneFromFile(lordCommander);
	//upadte the file
	voxel.pop_front();
	voxel.push_back(majnun);
	return (voxel.end() - 1);
}
template<class T>
inline typename deque<T>::iterator voxels<T>::getCode(unsigned long long mortonCode) {
	unsigned long long findThisOne = mortonCode;
	VoxelInfo temp_;
	temp_.morton = mortonCode;
	deque<T>::iterator temp = readOneCode(temp_);
	if (temp != voxel.end())
		return temp;
	else
		return readOneToUpdate(findThisOne);
}
template<class T>
inline voxels<T>::voxels(string address_, int levelL_, int levelH_, int size = 4096) {
	address = address_;
	levelL = levelL_;
	levelH = levelH_;
	size = size < 1 << (3 * levelH) ? size : 1 << (3 * levelH);
	for (int i = 0; i < size; i++) {
		voxel.push_back(readOneFromFile(i));
		cout << voxel[i] << endl;
	}
	cout << voxel.size();
}
template<class T>
inline typename deque<T>::iterator voxels<T>::readOneCode(T needed) {
	deque<T>::iterator temp = voxel.begin();
	for (; temp != voxel.end();temp++) {
		if (*temp == needed) {
			return temp;
		}
	}
	return voxel.end();
}