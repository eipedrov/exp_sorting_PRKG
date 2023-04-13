@echo off
set /p mensagem=Digite a mensagem de commit: 
set /p origem=Digite a origem: 
git add .
git commit -m "%mensagem%"
git push -u origin %origem%