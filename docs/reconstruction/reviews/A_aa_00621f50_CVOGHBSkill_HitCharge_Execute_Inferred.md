# Review A (reconstruction fidelity): `aa_00621f50` CVOGHBSkill_HitCharge_Execute_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00621f50` |
| **VA** | `0x00621f50`–`0x0062205d` |
| **Body** | **270 bytes** (`0x10E`) |
| **Canonical name** | `CVOGHBSkill_HitCharge_Execute_Inferred` |
| **Prior scaffold** | `FUN_00621f50` |
| **Review date** | `2026-08-05` (R12-005 dual seal) |
| **Reviewer role** | Independent reconstruction fidelity — Path A |
| **Counterpart** | `reviews/B_aa_00621f50_CVOGHBSkill_HitCharge_Execute_Inferred.md` |
| **System** | skills-abilities / CVOGHBSkill_HitCharge |
| **Parent dual** | `0x00621350` `CVOGHBSkill_OnDoHit_Ctor` (not rewritten here) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + `get_xrefs_to` / `get_function_xrefs` + `get_function_callees` + `get_function_callers` + `audit_globals_in_function`. **No** `disassemble_bytes`. No Launcher. Own VA only.

---

## 1. Purpose

`CVOGHBSkill_HitCharge` **vtbl+0x2C** multi-target arm:

1. Walk TFID table at `param_4` (stride `0x10`) until sentinel `{-1,-1,bGlobal=0}`.
2. Resolve each entry via `CVOGReaction_ResolveObjectTarget` (`ctx = world+0xe4e8`).
3. On hit: `new(0x6d0)` → call parent `CVOGHBSkill_OnDoHit_Ctor` (`FUN_00621350`) → overwrite vtbl to `PTR_FUN_009d1624` → zero HitCharge tail fields `+0x6c0` (dword 0) and `+0x6c4` (float 0.0).
4. If `owner@+0x18` set: `CVOGHBList_Enqueue(world+0xe4ec)` + `CVOGHBBase_Start`; else `vtbl[0](1)` deleting dtor.
5. Always **return 1** at sentinel.

Not the OnDoHit ctor (`FUN_00621350`); this unit **calls** that ctor per target then upgrades to HitCharge.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | `decompile_function` @ `0x00621f50` — **CF ≡** raw 2026-07-23 |
| Function meta | Body `00621f50`–`0062205e` (exclusive end); `get_function_by_address` |
| Disassembly | `disassemble_function` full body through `ret 0x18` |
| Bytes | `read_memory` 280 B @ entry + terminal `C2 18 00 CC` |
| RTTI | COL `0x00aae1f0` (vtbl-4) → type_info `0x00af2b4c` → `.?AVCVOGHBSkill_HitCharge@@` |
| Xref | sole DATA `0x009d1650` = vtbl+0x2C |
| Parent ctor | `FUN_00621350` OnDoHit (R11-017 dual; evidence only) |
| Peer execute | `FUN_00621700` OnDoHit execute size `0x6c0` / vtbl `009d15c4` — **do not merge** |
| Raw / clean | `aa_00621f50_*`, `CVOGHBSkill_HitCharge_Execute_Inferred.cpp` |

**Not performed:** Launcher, runtime, parent ledgers, dual of parent/siblings.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body `00621f50`–`0062205d`, 270 B (`0x10E`) | **Confirmed** | function meta + `ret` site |
| `ret 0x18` / six stack formals | **Confirmed** | `C2 18 00` @ `0062205c` |
| Return EAX=1 on sentinel | **Confirmed** | `B8 01 00 00 00` @ `0062204c` |
| ECX this unused | **Confirmed** | no ECX consumer as `this`; EBP = world arg |
| Stride `0x10` TFID table + sentinel | **Confirmed** | `shl 4` + triple compare |
| Resolve ctx `world+0xe4e8` | **Confirmed** | `mov ecx,[ebp+0xe4e8]` |
| Alloc size `0x6d0` | **Confirmed** | `push 0x6d0` |
| Parent = `CVOGHBSkill_OnDoHit_Ctor` @ `00621350` | **Confirmed** | `call 00621350` with ECX=new block |
| Vtbl imm `009d1624` after parent | **Confirmed** | `C7 06 24 16 9D 00` |
| Tail zero `+0x6c0` dword / `+0x6c4` float | **Confirmed** | `mov [esi+0x6c0],ebx` + `movss [esi+0x6c4],xmm0` |
| Class RTTI `CVOGHBSkill_HitCharge` | **Confirmed** | type_info string @ `0x00af2b54` |
| Slot = vtbl+0x2C | **Confirmed** | `009d1650 - 009d1624 = 0x2C` |
| Enqueue list `world+0xe4ec` | **Confirmed** | `mov ecx,[ebp+0xe4ec]` |
| Owner gate `+0x18` | **Confirmed** | `cmp [esi+0x18],ebx` |
| Product method English "Execute" | **Inferred** | family slot role; demangle open |
| Param product names beyond base map | **Probable** | via sealed OnDoHit/base ctor |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH prolog (`LAB_009a893b`) | Yes |
| Index loop / sentinel | Yes |
| ResolveObjectTarget | Yes |
| new 0x6d0 + OnDoHit ctor + HitCharge vtbl + tail zeros | Yes |
| Enqueue+Start vs dtor(1) | Yes |
| ret 0x18 / return 1 | Yes |

---

## 5. Gaps / open

1. Product C++ method name for vtbl+0x2C (Execute is role-inferred).
2. Semantic product English for HitCharge tail fields `+0x6c0` / `+0x6c4` (zeroed only here).
3. Whether any caller relies on ignored ECX instance state.
4. Upper bound on `index` (char wrap) — image unbounded until sentinel.
5. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
