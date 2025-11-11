r
break *main + 762
break *main + 709
commands
  silent
  set $val = *(unsigned long long*)($rsi)
  printf "Captured: 0x%llx\n", $val
  c
end
c
