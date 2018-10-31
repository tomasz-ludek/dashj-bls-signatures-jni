# dashj-bls-signatures-jni

git clone git@github.com:tomasz-ludek/dashj-bls-signatures-jni.git
cd dashj-bls-signatures-jni/

./build-bls-signatures.sh
./build-bls-wrapper.sh

Launch the sample java code:
java -cp src/java -Djava.library.path=build/ org.dash.bls.DashBlsJni