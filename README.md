# 背景
公司内部有一个自己的`mkl`库，由于时代久远(?)现在对其版本已经不可查。公司内部的`CAPI`一直是链接这个库的。后来，换成了`mklml`库，这个时候用户表示`CAPI`库cpu版本的性能下降了1倍到10倍不等。这个project是下降10倍的版本。

# 重现的步骤
## 编译环境
```
docker pull paddlepaddle/centos6u3-capi:latest-dev
```

## 对比时间
```
git clone https://github.com/gongweibao/testcapi.git
cd testcapi
docker run --rm -it -v $PWD:/root/test paddlepaddle/centos6u3-capi:latest-dev /bin/bash
cd /root/test
./build.sh
./run.sh
```

注：链接`mklml`的测试程序会core，但是在公司内部任何机器上跑都没有问题。具体的原因还需要查。


## 各个库是怎么编译出来的：
```
docker run --rm -it -v <your-paddle-repo-path>:/paddle paddlepaddle/centos6u3-capi:latest-dev /bin/bash
mkdir /paddle/build
cd /paddle/build
```

- mklml：
  - Paddle版本: `8b1c50c642914f6ab1fb691059d6d88d9995bea1`
   - 编译参数：
    ```
    cmake .. -DCMAKE_BUILD_TYPE=Release -DWITH_TESTING=OFF -DWITH_TEST=OFF -DRUN_TEST=OFF -DWITH_GOLANG=OFF -DWITH_PYTHON=OFF -DWITH_SWIG_PY=OFF -DWITH_DOC=OFF -DWITH_STYLE_CHECK=OFF -DWITH_GPU=OFF -DWITH_AVX=ON -DWITH_C_API=ON -DWITH_MKLDNN=ON -DWITH_MKLML=ON
    ```

- mkl
   - Paddle版本：`43c6ff212e2475b7f39480a9949b53119d332793`
   - 编译参数：
    ```
    cmake .. -DCMAKE_BUILD_TYPE=Release -DWITH_TESTING=OFF -DWITH_TEST=OFF -DRUN_TEST=OFF -DWITH_GOLANG=OFF -DWITH_PYTHON=OFF -DWITH_SWIG_PY=OFF -DWITH_DOC=OFF -DWITH_STYLE_CHECK=OFF -DWITH_GPU=OFF -DWITH_AVX=ON -DWITH_C_API=ON -DWITH_MKLDNN=ON -DWITH_MKLML=OFF
    ```