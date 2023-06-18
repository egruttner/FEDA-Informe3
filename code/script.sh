
#LIMPIA
rm main.o
rm csv/*.*
rm output/*.*


#REALIZA EXPERIMENTOS CON DIFERENTES DATASETS

num_datasets=1

for (( i=1; i <= $num_datasets; ++i ))
do
    make num_dataset=$i

done



