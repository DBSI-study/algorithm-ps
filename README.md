# algorithm-ps
두병장삼일병 레퍼지토리 1호입니다.

// 레퍼지토리 사용법(변경되었음)

** 개인 폴더만 변경하기!!
** 개인 폴더 안에 주차별로 관리하시면 됩니다!
** .gitignore 파일도 자기 파일 안에 저장하면 파일 내부에 들어있는
   파일들은 무시하고 push할 수 있습니다!

예) sickpickel->Week4->1937-sickpickel.cpp

### git pull error 해결법
- git pull 시도시,
"error: Your local changes to the following files would be overwritten by merge:
        goorm.manifest
Please commit your changes or stash them before you merge."
이런 에러가 났다면, 한 브랜치(main)에서 여러 사람이 작업하여 자신의 로컬 저장소보다 원격 저장소의 변경사항이 더 많은 경우이다.

# git stash
# git pull
# git stash pop

위의 명령어로 해결가능하다.

// 좋은 글 감사합니다. ++ TMI 추가

merge로 인해서 overwritten 되는 경우는, 위의 말처럼 같은 파일에 대해서 원격 저장소와 나의 로컬 저장소가 다른 내용을 가지고 있고,
나의 로컬 저장소에서 내가 변화시킨 부분을 commit 하거나 stash 시키지 않았을 경우 일어날 수 있음.(깃에서 내가 바꾼 내용이 날라가지 않도록 방지)

즉, 개인 폴더 밖에 있는 README.md나 .gitignore 파일을 수정 시에 pull 에러가 뜨면 위의 명령어로 해결해주시면 됩니다!

