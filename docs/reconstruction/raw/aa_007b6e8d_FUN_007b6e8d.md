# Raw capture: FUN_007b6e8d

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b6e8d` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x007b6e8d` |
| **Canonical name** | `FUN_007b6e8d` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
bool FUN_007b6e8d(void)

{
  int iVar1;
  int *piVar2;
  int unaff_EBP;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (unaff_ESI < 0) {
    FUN_007a4480(1,"Failed to load XML file %s, failed with code %d",
                 *(undefined4 *)(unaff_EBP + 0xc));
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(short *)(unaff_EBP + -0x28) != -1) {
    iVar1 = **(int **)(unaff_EBP + 8);
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    (**(code **)(iVar1 + 0xf0))(*(int **)(unaff_EBP + 8),unaff_EBP + -0x14);
    piVar2 = *(int **)(unaff_EBP + -0x14);
    if (piVar2 != (int *)0x0) {
      *(undefined4 *)(unaff_EBP + 8) = 0;
      (**(code **)(*piVar2 + 0x20))(piVar2,unaff_EBP + 8);
      *(undefined4 *)(unaff_EBP + -0x20) = 0;
      (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x24))
                (*(int **)(unaff_EBP + -0x14),unaff_EBP + -0x20);
      *(undefined4 *)(unaff_EBP + -0x1c) = 0;
      (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x2c))
                (*(int **)(unaff_EBP + -0x14),unaff_EBP + -0x1c);
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      (**(code **)(**(int **)(unaff_EBP + -0x14) + 0x30))
                (*(int **)(unaff_EBP + -0x14),unaff_EBP + -0x18);
      FUN_007a4480(1,"%S(%i)(%s): pos %i, XML parse error: %S",*(undefined4 *)(unaff_EBP + 8),
                   *(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + 0xc),
                   *(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x20));
      SysFreeString(*(BSTR *)(unaff_EBP + 8));
      SysFreeString(*(BSTR *)(unaff_EBP + -0x20));
      (**(code **)(**(int **)(unaff_EBP + -0x14) + 8))(*(int **)(unaff_EBP + -0x14));
    }
    ExceptionList = *(void **)(unaff_EBP + -0xc);
    return false;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return -1 < unaff_ESI;
}
```

## Live re-verify append (2026-07-29 W19-S)

| Check | Result |
|---|---|
| `decompile_function` @ `0x007b6e8d` | **≡** raw CF; **bytes seal extra** `push ESI` for `%d` (decompiler omitted second log arg) |
| `get_function_by_address` | Body **`007b6e8d`–`007b6f81`** |
| `read_memory` length 64 @ entry | `85 f6 c7 45 fc 00 00 00 00 7d 14 8b 55 0c 56 52 68 f0 5e a9 00 6a 01 e8 …` |
| Entry seal | `test esi,esi; mov [ebp-4],0; jge skip_log; mov edx,[ebp+0xc]; **push esi**; push edx; push fmt; push 1; call log; add esp,10` |
| Fail log string @ `0x00a95ef0` | `"Failed to load XML file %s, failed with code %d"` |
| Parse log format (decompile) | `"%S(%i)(%s): pos %i, XML parse error: %S"` (url BSTR, line, path, linepos, reason BSTR) |
| Epilogue seal | both arms: restore `ExceptionList` from `[ebp-0xc]`; **`ret 8`** (`c2 08 00`) — cleans **2 stack args** of parent thiscall load |
| Return | `VARIANT_BOOL != -1` → dump parseError + **`xor al,al`** (false); else **`setge al`** from `cmp esi, ebx` (ebx=0) → true iff **HRESULT ≥ 0** |
| Sole caller | `NDXml_LoadDocumentFromPath` @ `0x007b6e6f` (UNCONDITIONAL_CALL) — **outlined load epilogue** using **caller EBP frame** |
| Callees | `FUN_007a4480` (log), `SysFreeString`×2, COM vcalls on `IXMLDOMDocument` / `IXMLDOMParseError` |
| COM map (dual IDispatch) | doc `vtbl+0xf0` = `get_parseError`; err `+0x20` get_url, `+0x24` get_reason, `+0x2c` get_line, `+0x30` get_linepos, `+8` Release |

**Structural name (W19-S):** `NDXml_FinishLoadResult`.

