# Raw capture: FUN_0044dad0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044dad0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0044dad0` |
| **Canonical name** | `FUN_0044dad0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0044dad0(void)

{
  bool bVar1;
  int iVar2;
  int *unaff_EBX;
  int unaff_ESI;
  basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_> *unaff_EDI;
  
  iVar2 = FUN_0044dfc0(unaff_EDI);
  if (iVar2 != *(int *)(unaff_ESI + 4)) {
    bVar1 = std::operator><char,struct_std::char_traits<char>,class_std::allocator<char>_>
                      (unaff_EDI,
                       (basic_string<char,struct_std::char_traits<char>,class_std::allocator<char>_>
                        *)(iVar2 + 0xc));
    if (!bVar1) {
      *unaff_EBX = iVar2;
      return;
    }
  }
  *unaff_EBX = *(int *)(unaff_ESI + 4);
  return;
}
```
