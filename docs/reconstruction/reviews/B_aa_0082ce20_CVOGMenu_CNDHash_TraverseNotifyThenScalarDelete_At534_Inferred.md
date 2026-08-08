# Review B (skeptical / adversarial): `aa_0082ce20` CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0082ce20` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-05` (WQ9L-H2) |
| **Counterpart** | `reviews/A_aa_0082ce20_CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_assembly_context` + callee decompiles. **No** `disassemble_bytes`. No Launcher.

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is the full CVOGMenu complete destructor | **Falsified** — parent `FUN_0082d540` installs vtbl, calls this, then `CNDUIDialog_CompleteDtor`; this only tears hash@+0x534 |
| 2 | Hard-aborts on TraversalLock errors | **Falsified** — soft log via `FUN_007a4480` then continues (forces lock / keeps walking) |
| 3 | Same unit as host hash teardown-recreate (`0x007fe640` family) | **Falsified** — host offset different; ordered next@+0x14 not +0x20; **scalar-delete** not recreate |
| 4 | Frees CVOGMenu `this` | **Falsified** — bare RET; nulls hash slot only; no `operator_delete(this)` |
| 5 | Nested list helpers take entry\* (not entry+8) | **Falsified** — `LEA ESI,[EAX+8]; MOV ECX,ESI` before `FUN_004294f0` / `FUN_00410d60` |
| 6 | `FUN_004113b0` is 2-arg stdcall as bare decompile shows | **Falsified** — thiscall: ECX=&iter_state; stack list + out\*; decompiler elided ECX |
| 7 | Hash slot is `param_1[0x14d]` only as abstract index | **Survives as +0x534** — bytes `MOV ESI,[EBP+0x534]` / null same |
| 8 | Notify target is fixed free function | **Falsified** — `CALL [EDX+0xbc]` virtual on menu |
| 9 | Sibling `0x00415e90` is alternate form of this helper | **Falsified** — `StdList_Clear_ESI` is unrelated std::list clear (dialog +0x4dc); different ABI/role |
| 10 | Safe no-op when hash slot null | **Survives** — early JE on ESI==0 |
| 11 | Runtime Confirmed / bit-exact | **Open / not claimed** — no Launcher |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Role = menu-owned hash traverse-notify-scalar-delete | **High** | wrong port lifecycle / double-free hash |
| ECX thiscall +0x534 slot | **High** | wrong field / crash |
| Nested list @ entry+8 | **High** | lock wrong object / CS corruption |
| Soft asserts only | **High** | over-strict port aborts teardown |
| Product value_type / vtbl[+0xbc] English | **Open** | wrong notify semantics if guessed |
| Exact CNDHash stamp of slot object | **Open** | wrong dtor pairing if inventing type |
| Runtime | **Open** | matrix policy |

---

## 3. Cross-check against raw + bytes

```text
// FUN_0082ce20 entry
SUB  ESP, 8
PUSH EBX
PUSH EBP
MOV  EBP, ECX              ; this
PUSH ESI
MOV  ESI, [EBP+0x534]      ; owned hash*
XOR  EBX, EBX
CMP  ESI, EBX
JE   exit                  ; null → return

; … TraversalLock soft-assert; force [hash+0x1d]=1 …

; per ordered node:
LEA  ESI, [EAX+8]          ; nested list shell
MOV  ECX, ESI
CALL FUN_004294f0          ; lock
; FUN_004113b0(ECX=&state, list, &value); while ret==0: CALL [menu.vtbl+0xbc](value)
; if [ESI+0x28]: clear; LeaveCriticalSection(ESI+4)
MOV  ECX, ESI
CALL FUN_00410d60          ; destroy owned chain

; after walk:
MOV  EAX, [EBP+0x534]
MOV  [EAX+0x1d], BL        ; unlock TraversalLock
MOV  ECX, [EBP+0x534]
CMP  ECX, EBX
JE   skip_dtor
MOV  EDX, [ECX]
PUSH 1
CALL [EDX]                 ; scalar-deleting dtor
skip_dtor:
MOV  [EBP+0x534], EBX      ; null slot
POP  ESI / EBP / EBX
ADD  ESP, 8
RET
```

Live decompile 2026-08-05 ≡ raw 2026-07-23 CF. Nested ECX + iterate ABI sealed by mid-body `read_memory` + callee decompiles.  
Parent site `0x0082d56b`: `MOV ESI,ECX; … CALL 0082ce20; MOV ECX,ESI; CALL 00792c20`.  
Secondary `0x0082f168`: three explicit vtbl[+0xbc] notifies then this helper then tail-jmp vtbl[+0x3ac].

---

## 4. Surviving contract for AutoCore

```cpp
// ECX = CVOGMenu* this; void; bare RET after SUB ESP,8
void CVOGMenu_CNDHash_TraverseNotifyThenScalarDelete_At534(void* self) {
  void** slot = (void**)((char*)self + 0x534);
  void* hash = *slot;
  if (!hash) return;

  // soft-assert TraversalLock @ hash+0x1d; force locked
  // walk ordered nodes: head = *(hash+0x14), next = *(node+0x14), entry = *(node+8)
  // for each entry:
  //   list = entry+8
  //   TraversalLock(list)           // FUN_004294f0
  //   while iterate(list, &value)==0:  // FUN_004113b0
  //     menu->vtbl[0xbc/4](value)
  //   unlock list CS if held; destroy owned chain // FUN_00410d60
  // unlock hash TraversalLock
  // if hash: hash->vtbl[0](1)       // scalar-delete
  // *slot = nullptr
}
// Do NOT free CVOGMenu this.
// Do NOT merge with host recreate teardown or StdList_Clear_ESI.
// Do NOT invent product English for value_type / notify method.
```

**Gaps (honest):** product hash stamp / RTTI of object at +0x534; vtbl[+0xbc] method English; nested list element type destroyed by `FUN_00410d60`; runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**.
