# Review A (reconstruction fidelity): `aa_00792490` UiWidget_TeardownIfActive

| Field | Value |
|---|---|
| **Stable ID** | `aa_00792490` |
| **VA** | `0x00792490`–`0x007925ff` |
| **Canonical name** | `UiWidget_TeardownIfActive` |
| **Ghidra name** | `FUN_00792490` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W22-F) |
| **Counterpart** | `reviews/B_aa_00792490_UiWidget_TeardownIfActive.md` |
| **System** | ui |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory`; callers FlushPreparedResponse + thin `vtbl+0x3ac` wrappers |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Shared UI widget teardown: if `vtbl+0x3d8` reports active, clear flags, release owned resources, hash-walk children via `vtbl+0xb0`, then free residual pointers. Used by 100+ close paths (often after `vtbl+0x3ac`).

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00792490_FUN_00792490.md` (+ 2026-07-29 append) |
| Annotated | `docs/reconstruction/raw/aa_00792490_FUN_00792490.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UiWidget_TeardownIfActive.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00792490.cpp` |
| Function record | `docs/reconstruction/functions/aa_00792490_FUN_00792490.md` |
| Mission flush | `Client_MissionDialog_FlushPreparedResponse` `0x008ab8f0` |
| Thin wrapper | `FUN_00817610` = `vtbl+0x3ac` then this |
| Live | decompile ≡ raw; body 368 B; prologue `PUSH ESI; MOV ESI,ECX`; epilogue `POP EBX; POP ESI; RET` |

---

## 3. Signature (sealed)

```c
// ECX = this; void; RET
void __fastcall UiWidget_TeardownIfActive(void* self);
```

| Formal | Source | Conf |
|---|---|---|
| self | **ECX** | **High** |
| stack args | none | **High** |
| return | void | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
if !vtbl[0x3d8](): return
vtbl[0x330](8)
clear +0x8c/+0xc8/+0x492
if +0x2ac: release +0x2a8 ref; FUN_0074e260; dtor +0x2ac
vtbl[0x58]()
lock hash +0x4d8; walk chain; vtbl[0xb0](value); unlock
vtbl[0x3b4]()
if vtbl[0x1c0](): dtor +0x2a8
dtor +0x4c0; zero residual ptrs
```

| Stage | Match | Conf |
|---|---|---|
| Gate + early ret | **Yes** | **High** |
| Flag clears offsets | **Yes** | **High** |
| Resource release + FUN_0074e260 | **Yes** | **High** |
| Hash lock/walk/unlock | **Yes** | **High** |
| Residual ptr clears | **Yes** | **High** |
| vtbl product English | residual | **Tentative** |

---

## 5. Machine bytes (`read_memory`)

Prologue seals ECX→ESI thiscall/fastcall. Gate: `CALL [EAX+0x3D8]; TEST AL,AL; JZ epilogue`.  
Epilogue: `POP EBX; POP ESI; RET` (no stack arg cleanup).  
Strings via relative calls to `FUN_007a4480`.

---

## 6. Gaps

- Product English for `vtbl+0x330(8)`, `+0x3ac`, `+0xb0`, `+0x1c0`.
- Concrete type of object at `+0x2ac` / hash value payload.
- Live leak/teardown differential when gate is false.

## Verdict rationale

ABI, gate, offsets, hash walk, and call pattern sealed High from decompile + bytes + many callers. Residual is vtbl product naming / types → **accept-with-gaps**.
