# Review A (reconstruction fidelity): `aa_0053dbb0` CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0053dbb0` |
| **VA** | `0x0053dbb0`–`0x0053dcf6` |
| **Body** | **327 bytes** |
| **Canonical name** | `CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred` |
| **Prior scaffold** | `FUN_0053dbb0` |
| **Review date** | `2026-07-29` (W26-E dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0053dbb0_CVOGObject_ApplyModeFlag_RebindSwitchHBAI_Inferred.md` |
| **System** | object lifecycle / AI mode apply |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` + `analyze_function_complete` + `get_function_by_address`. No `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Virtual **mode-flag apply** on CVOGObject:

| Stage | Behavior |
|---|---|
| Gate | `this[+8]` (world host) non-null |
| Flag==0 | self vtbl **+0x10** |
| Flag≠0 | self vtbl **+0xc**; `*(host+0x28)=0x10`; children vtbl+8(4) |
| Always | `WorldObj_RebindActivate(host,1)` |
| AI notify | locked `*(host+0x3c)` vtbl **+0x50** then **+0x54** with `DAT_00b04610` |
| Optional | `SwitchHBAIByCode(1)` if flag==0, else `(6)`, when host lacks both `+0x40` and `+8` |

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra @ `0x0053dbb0` |
| Bytes | prologue gate + tail `JMP 0x005d4440` with stack rewrite 1/6 |
| Bounds | body `0053dbb0`–`0053dcf6` (327 B) |
| Xrefs | 8 rdata vtable slots; 0 direct callers |
| Downstream duals | `WorldObj_RebindActivate` (W24-B); `CVOGObject_SwitchHBAIByCode` |
| Raw / clean | `aa_0053dbb0_*`, named clean |

**Not performed:** Launcher, runtime, child-list duals, lock-helper duals.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| thiscall + char flag; ret 4 | **Confirmed** | `mov esi,ecx`; `mov bl,[esp+10h]`; `C2 04 00` |
| Virtual method | **Confirmed** | rdata-only xrefs |
| Rebind always when host set | **Confirmed** | `call FUN_00560e90` |
| Tail SwitchHBAI 1 vs 6 | **Confirmed** | both JMP → `0x005d4440` |
| needsSwitch algebra | **Confirmed** | decompiler double-neg reduces to missing flag/host |
| Stamp `0x10` product meaning | **Probable** | constant only |
| Child arg `4` English | **Tentative** | |
| Product modeFlag English | **Inferred** | structural 0 vs nonzero |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Host gate | Yes |
| Mode branch vfuncs | Yes |
| Child fan-out | Yes |
| RebindActivate | Yes |
| Dual AI lock+notify | Yes |
| Conditional SwitchHBAI 1/6 | Yes |
| ret 4 / tail | Yes |

---

## 5. Gaps / open

1. Which 8 CVOG subclasses install this vtable slot.
2. Product names for mode flag and stamp `0x10`.
3. Why AI codes **1** and **6** specifically (normal vs WalkingCreatureTurreted).
4. Runtime / bit-exact.

**Verdict:** **accept**
