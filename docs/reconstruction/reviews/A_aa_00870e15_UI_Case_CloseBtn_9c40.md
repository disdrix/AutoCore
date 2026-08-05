# Review A (reconstruction fidelity): `aa_00870e15` UI_Case_CloseBtn_9c40

| Field | Value |
|---|---|
| **Stable ID** | `aa_00870e15` |
| **VA** | `0x00870e15` |
| **Canonical name** | `UI_Case_CloseBtn_9c40` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (fidelity) |
| **Counterpart** | `reviews/B_aa_00870e15_UI_Case_CloseBtn_9c40.md` |
| **System** | UI dialog message switch |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Jump-table case** for UI control id **`0x9c40` (40000 / close)** in parent message handler `0x00870a90`. On activate message **8**, optionally leaves the dialog via generic host **`FUN_007fca10`** when selection field **`this+0x50c == -1`**; otherwise swallows close. Non-activate messages forward to **`FUN_0087b500`**.

Not a network builder, not mission response fill, not trade-grid logic.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Live Ghidra (3×) | `decompile_function` + `force_decompile` + `batch_decompile` @ `0x00870e15` — **identical** |
| Body bytes | `read_memory(0x00870e15, 47)` |
| Parent prologue | `read_memory(0x00870a90, 48)` |
| Jumptable[0] | `read_memory(0x00870e44, 4)` = `0x00870e15` |
| Xrefs | DATA `0x00870e44`; COMPUTED_JUMP `0x00870aaa` |
| Function meta | body `00870e15–00870e43`; callees `FUN_007fca10`, `FUN_0087b500` |
| Raw | `docs/reconstruction/raw/aa_00870e15_FUN_00870e15.md` |
| Annotated | `docs/reconstruction/raw/aa_00870e15_FUN_00870e15.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_Case_CloseBtn_9c40.cpp` |
| Peer leave host | dual `aa_007fca10` (context only) |

---

## 3. Signature / ABI

```c
// Parent thiscall entry 0x00870a90:
//   ECX = this → EDI
//   [esp+4] = msg → EAX
//   [esp+8] = controlId → EDX
//   switch (controlId - 0x9c40) cases 0..11; case 0 → this VA
// Case tails: pop edi; ret 8

uint32_t UI_Case_CloseBtn_9c40(void* this, int msg, uint32_t controlId);
```

| Claim | Confidence | Notes |
|---|---|---|
| EDI = this | **High** | parent `mov edi,ecx`; body `[edi+0x50c]`; leave `mov eax,edi` |
| EAX = msg | **High** | parent `mov eax,[esp+4]`; `cmp eax,8` |
| EDX = controlId | **High** | parent `mov edx,[esp+8]`; pushed to `FUN_0087b500` |
| RET 8 | **High** | both tails `C2 08 00` |
| Decompiler `param_1` unused | **High** | phantom; ignore |
| Decompiler omits ECX on `FUN_0087b500` | **High** | bytes: `mov ecx,edi` before call |

---

## 4. Control flow (sealed)

```
cmp eax, 8
jne FORWARD

  cmp dword [edi+0x50c], -1
  jne RET1
    push ebx
    mov eax, edi
    mov ebx, 0x00d1a840
    call FUN_007fca10
    pop ebx
  RET1:
    mov al, 1
    pop edi
    ret 8

FORWARD:
  push edx
  push eax
  mov ecx, edi
  call FUN_0087b500
  pop edi
  ret 8
```

| Stage | Match decompile | Match bytes |
|---|---|---|
| msg==8 gate | Yes | Yes |
| +0x50c == -1 gate | Yes | Yes |
| leave only when unselected | Yes | Yes |
| always return 1 on msg 8 | Yes | `mov al,1` |
| else FUN_0087b500 | Yes (args incomplete in decomp) | thiscall sealed |

---

## 5. Confirmed claims

| # | Claim | Confidence |
|---|---|---|
| 1 | Case id is close **`0x9c40`** | **High** — table index 0 under `lea ecx,[edx-0x9c40]` |
| 2 | Activate message is **8** | **High** |
| 3 | Selection sentinel **`this+0x50c == -1`** gates leave | **High** |
| 4 | Leave host **`FUN_007fca10`** with EAX=this, EBX=`0x00d1a840` | **High** |
| 5 | Selected state blocks leave but still returns 1 | **High** |
| 6 | Non-8 → **`FUN_0087b500(this,msg,controlId)`** | **High** |
| 7 | Body size 0x2F bytes (`…e15`–`…e43`) | **High** |
| 8 | Out-of-range parent `ja` lands on this case’s FORWARD tail | **High** (parent context) |

---

## 6. Gaps

1. Product/RTTI name of dialog class owning vtable slot → `0x00870a90`.
2. Semantic type of `+0x50c` beyond “−1 = none” (sibling `FUN_00870680` writes it).
3. Whether this class’s `vtbl+0x440` is Flush vs plain hide (depends on class; leave host is generic).
4. Runtime / wire / bit-exact image open.

---

## 7. AutoCore impact

- Client UI only for this case body.
- Ports of this dialog must **not** close on `0x9c40` click while `+0x50c != -1`.
- Do not confuse with mission-dialog close path in `FUN_008aec40` (different parent; same id constant and same leave host).
