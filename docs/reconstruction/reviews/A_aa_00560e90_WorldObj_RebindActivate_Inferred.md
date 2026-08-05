# Review A (reconstruction fidelity): `aa_00560e90` WorldObj_RebindActivate_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00560e90` |
| **VA** | `0x00560e90`–`0x00560eb1` |
| **Body** | **34 bytes** |
| **Canonical name** | `WorldObj_RebindActivate_Inferred` |
| **Prior scaffold** | `FUN_00560e90` |
| **Review date** | `2026-07-29` (W24-B dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00560e90_WorldObj_RebindActivate_Inferred.md` |
| **System** | world-object / phys rebind |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Thin **manager** helper used after phys mode/recreate paths:

| Step | Callee / write | Role |
|---|---|---|
| 1 | `FUN_0055fbf0(manager, obj)` | unbind / remove links |
| 2 | `FUN_0055fa40(manager, obj)` | re-bind / re-link |
| 3 | `*(obj+0x44)+0x28 = 1` | mark linked/active flag |

Not a full enroll (`00560ec0` counters/refcount) and not a full remove (`00561450`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x00560e90` (+ nested unbind/bind) |
| Bytes | `read_memory` 48 B — `mov esi,ecx`, dual calls, flag store, `ret 8` |
| Bounds | body `00560e90`–`00560eb1` |
| Callees | `0055fbf0`, `0055fa40` |
| Callers | recreate/airlift/phys: `005dac00`, `00979290`, `00979310`, `0053dbb0`, `004c4880`, `005f44c0`, … |
| Siblings | enroll `00560ec0`, remove `00561450` (sealed elsewhere) |
| Raw / clean | `aa_00560e90_*`, `WorldObj_RebindActivate_Inferred.cpp` |

**Not performed:** Launcher, runtime, parent ledgers, dual of unbind/bind helpers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| ECX = manager (`mov esi,ecx`) | **Confirmed** | bytes |
| Stack #1 = object (EDI) | **Confirmed** | `mov edi,[esp+0xc]` after 2 pushes |
| `ret 8` (two stack dwords) | **Confirmed** | `C2 08 00` |
| Body never reads stack #2 | **Confirmed residual** | no load of second formal |
| Unbind then bind order | **Confirmed** | call order |
| Flag `*(obj+0x44)+0x28=1` | **Confirmed** | `mov eax,[edi+0x44]; mov byte [eax+0x28],1` |
| Decompiler omits `this` | **Confirmed residual** | surface shows only object |
| Product manager class English | **Inferred** | structural WorldObj |
| Flag product meaning | **Probable** | “linked/active” from call-site context |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Save this / load obj | Yes |
| call unbind | Yes |
| call bind | Yes |
| flag write | Yes |
| ret 8 | Yes (documented) |

---

## 5. Gaps / open

1. Product English for manager + flag at `sub+0x28`.
2. Semantic of staged second formal (always 1 at several sites; unread here).
3. Full contracts of `0055fbf0` / `0055fa40` — out of OWN.
4. Runtime / bit-exact / differential.

**Verdict:** **accept**
