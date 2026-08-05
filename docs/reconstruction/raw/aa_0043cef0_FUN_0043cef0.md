# Raw capture: FUN_0043cef0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043cef0` |
| **Module** | `autoassault.exe` |
| **Image base** | `0x400000` |
| **VA** | `0x0043cef0` |
| **Canonical name** | `FUN_0043cef0` |
| **System** | unknown |
| **Capture timestamp** | `2026-07-23` |
| **Tool** | Ghidra MCP `batch_decompile` |
| **Integrity** | Do not overwrite this raw body; append versioned sections only |

---

## Raw pseudocode (authoritative decompile)

```c
void FUN_0043cef0(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 *unaff_EBX;
  
  for (; (param_1 != param_3 || (param_2 != param_4)); param_2 = param_2 + 1) {
    uVar2 = param_2 >> 2;
    iVar1 = uVar2 * -4;
    if (*(uint *)(param_1 + 8) <= uVar2) {
      uVar2 = uVar2 - *(uint *)(param_1 + 8);
    }
    *(undefined4 *)(*(int *)(*(int *)(param_1 + 4) + uVar2 * 4) + (param_2 + iVar1) * 4) =
         *unaff_EBX;
  }
  return;
}
```

---

# Raw capture: FUN_0043cef0 — W28-D re-verify append

## Live re-verify 2026-07-29 (OWN-ONLY dual W28-D)

**Tools:** `decompile_function` + `read_memory` + `analyze_function_complete` (+ callers/callees). **No** `disassemble_bytes`.  
**Live decompile = raw 2026-07-23** for full body.  
**Body:** `0x0043cef0`–`0x0043cf38` (**73 B** / `0x49`; pad `CC` then `FUN_0043cf40`).  
**Classification:** **leaf** (0 callees).  
**Callers (1):** `FUN_0043cb00` only — 3 xrefs `0x0043cbdd`, `0x0043cd1c`, `0x0043cde6`.

### Control flow (sealed)

```
// Stack (cdecl/plain RET; caller cleans): p1=container_a, p2=idx_from, p3=container_b, p4=idx_to
// EBX = pointer to dword fill value (unaff_EBX / caller-owned)
// Loop half-open: while (container_a != container_b || idx_from != idx_to):
//   page = idx_from >> 2
//   sub  = idx_from - page*4   // == idx_from % 4
//   if (page >= [container_a+0x08] /*capacity pages*/) page -= capacity
//   slots = [container_a+0x04]
//   page_ptr = [slots + page*4]
//   [page_ptr + sub*4] = *EBX
//   idx_from++
// plain RET (no RET N)
```

### Entry / epilogue bytes (`read_memory`)

```
8B 54 24 08       MOV EDX, [ESP+8]      ; idx_from
55                PUSH EBP
8B 6C 24 14       MOV EBP, [ESP+0x14]   ; idx_to
56 57             PUSH ESI / EDI
8B 7C 24 10       MOV EDI, [ESP+0x10]   ; container_a
…
8B 33             MOV ESI, [EBX]        ; *fill
89 34 88          MOV [EAX+ECX*4], ESI  ; store
83 C2 01          ADD EDX, 1
EB CB             JMP loop
5F 5E 5D C3       POP EDI/ESI/EBP; RET
```

Full body hex (73 B):

```
8b542408558b6c241456578b7c2410903b7c241875043bd5742b8bc2c1e8028d0c85000000008bf18bca2bce8b77083bf077022bc68b77048b04868b3389348883c201ebcb5f5e5dc3
```

### Named role (Inferred)

`GuardedVector_RingFillRange` — assign `*EBX` across half-open absolute ring indices using map pages at `+0x04` and page capacity at `+0x08` (same family as `GuardedVector_RingCopyRange` / EraseRange).

