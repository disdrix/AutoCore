void * __thiscall FUN_005d6dc0(void *param_1,byte param_2)

{
  thunk_FUN_005d2470();
  if ((param_2 & 1) != 0) {
                    /* WARNING: Subroutine does not return */
    operator_delete(param_1);
  }
  return param_1;
}
