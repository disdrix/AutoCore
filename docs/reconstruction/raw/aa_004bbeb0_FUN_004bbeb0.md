# Raw capture: FUN_004bbeb0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bbeb0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x004bbeb0` |
| **Canonical name** | `FUN_004bbeb0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void __fastcall FUN_004bbeb0(int param_1)

{
  FUN_004bcce0(5);
  FUN_004bc580();
  FUN_004bc580();
  FUN_004bc580();
  FUN_00410420(0,0);
  FUN_00410420(0,0);
  FUN_00410420(0,0);
  if (*(char *)(param_1 + 0xc) != '\0') {
    (**(code **)(**(int **)(param_1 + 4) + 4))();
  }
  if (*(char *)(param_1 + 0xd) != '\0') {
                    /* WARNING: Could not recover jumptable at 0x004bbf13. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(param_1 + 8) + 4))();
    return;
  }
  return;
}
```

---

## W31-N re-verify (2026-07-29) — append only

| Field | Value |
|---|---|
| **Tools** | `batch_decompile` / `decompile_function` + `analyze_function_complete` + `read_memory` + callers/xrefs. **No** `disassemble_bytes` |
| **Live decompile** | ≡ raw 2026-07-23 CF; **loses** per-call ECX targets and mislabels second vtbl path as jumptable |
| **Body** | `0x004bbeb0`–`0x004bbf18` exclusive (**104 B** / `0x68`); pad `CC`; next `FUN_004bbf20` |
| **ABI** | ECX=`this` (`56 8B F1`); bare `C3`; void |
| **Callees** | `FUN_004bcce0` (CNDHash_Recreate_009cb450, W30-G), `FUN_004bc580`×3, `FUN_00410420`×3; optional `vtbl[+4]` on `*(this+4)` / tail `*(this+8)` |
| **Callers** | `FUN_004d98f0` @ `0x004d9a61`; `FUN_00943b80` @ `0x00943d72` (client/host teardown paths) |
| **Classification** | worker |

### Full body hex (104 B)

```
568bf18b4e186a05e8230e00008b4e1ce8bb0600008b4e20e8b30600008b4e24e8ab0600006a006a008d4e48e83f45f5ff6a006a008d4e28e83345f5ff6a006a008d4e38e82745f5ff807e0c0074088b4e048b01ff5004807e0d0074098b4e088b115eff62045ec3
```

### Byte-sealed algorithm (overrides decompiler this-loss)

```
ESI = this
// 1) CNDHash Recreate tableC (family 009cb450) log2=5 on *pointer* at this+0x18
ECX = *(this+0x18); push 5; call FUN_004bcce0   // ret 4 callee

// 2) Drain/clear three locked-list hosts via pointers
ECX = *(this+0x1c); call FUN_004bc580
ECX = *(this+0x20); call FUN_004bc580
ECX = *(this+0x24); call FUN_004bc580

// 3) Resize-to-zero three embedded dword vectors (size=0, fill=0)
push 0; push 0; lea ECX,[this+0x48]; call FUN_00410420
push 0; push 0; lea ECX,[this+0x28]; call FUN_00410420
push 0; push 0; lea ECX,[this+0x38]; call FUN_00410420

// 4) Optional owned interfaces
if flag@+0x0c: ECX=*(this+4); CALL [vtbl+4]
if flag@+0x0d: ECX=*(this+8); POP ESI; JMP [vtbl+4]  // tail call
else: POP ESI; RET
```

### Residuals closed by bytes

- Decompiler shows bare `FUN_004bcce0(5)` / `FUN_004bc580()` without this — **bytes seal** ECX loads.
- "Jumptable at 0x004bbf13" — **false**; `FF 62 04` is **tail JMP** vtbl[+4].
- Vectors are **embedded** (`LEA ECX,[ESI+disp]`); hash/queues are **heap pointers** (`MOV ECX,[ESI+disp]`).
