int main(){

    // スレッドローカルストレージと呼ばれる記憶域。スレッドの開始から終了までの有効期間を持つ。

    thread_local int thread_data = 10;
    
    return 0;

}
