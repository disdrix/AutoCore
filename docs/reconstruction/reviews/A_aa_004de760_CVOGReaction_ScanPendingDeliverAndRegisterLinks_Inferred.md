# Review A (reconstruction fidelity): `aa_004de760` CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004de760` |
| **VA** | `0x004de760` |
| **Body** | `0x004de760`–`0x004de9e6` (647 bytes / `0x287`) |
| **Canonical name** | `CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred` |
| **Prior scaffold** | `FUN_004de760` |
| **Review date** | `2026-07-29` (W23-M dual seal) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004de760_CVOGReaction_ScanPendingDeliverAndRegisterLinks_Inferred.md` |
| **System** | missions-progression / object-hash links |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Host method that **binds pending Deliver objectives to world objects** via the object-hash register peer:

1. Lock character pending-objectives hash (`+0x55c`, lock byte `+0x1d`).
2. Traverse hash nodes; for each objective, scan evaluator vector (`+0x158/+0x15c`).
3. Keep Deliver evaluators: vcall `+0x50 == 3` + RTTI cast to `CVOGObjectiveRequirement_Deliver`.
4. Filter by `deliver+0x1c == host+0xfc`.
5. Match objects (full host list or single optional) where MI `+0x34 == deliver+0x18`.
6. Predicate vcall `+0xc` chooses register mode **5** vs **8**; call `FUN_004dbef0`.
7. Unlock on empty traversal.

Callers include Patrol init-active, Deliver host path `FUN_00610e60`, host queue `FUN_004dea70`, and give-item `FUN_0080af70`.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x004de760` |
| Entry/exit bytes | `read_memory` @ entry + `@0x004de9d0` — `ret 8`, lock/unlock |
| Bounds | `get_function_by_address` body `004de760`–`004de9e6` |
| Callees / callers | `analyze_function_complete` |
| Peer dual | `aa_004dbef0` RegisterObjectHashEntry |
| Deliver type | sealed type **3** (peer ctor duals) |
| Raw / clean | `aa_004de760_*`, named + FUN clean |

**Not performed:** Launcher, runtime, parent ledgers, `disassemble_bytes`.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| `__thiscall` + **`ret 8`** | **Confirmed** | epilogue `C2 08 00` |
| ECX host saved | **Confirmed** | `mov [esp+..], ecx` |
| Pending hash `character+0x55c` | **Confirmed** | entry loads + registry |
| TraversalLock `hash+0x1d` | **Confirmed** | strings + stores |
| Deliver type code **3** | **Confirmed** | `cmp` after vcall `+0x50` |
| RTTI Deliver cast | **Confirmed** | decompile symbols + push immediates |
| Match `host+0xfc` / `deliver[7]` | **Confirmed** | decompile |
| Modes **5** / **8** to `FUN_004dbef0` | **Confirmed** | decompile constants |
| Optional object null ⇒ list scan | **Confirmed** | decompile branch |
| Product name of `+0xfc` / modes | **Inferred** residual | gaps |
| Not RTTI type descriptor | **Confirmed** | executable body + ret |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Lock / unlock | Yes (entry + epilogue bytes) |
| Hash walk | Yes |
| Evaluator loop + type 3 | Yes |
| Deliver cast + host filter | Yes |
| Object list vs single | Yes |
| Register 5/8 | Yes |
| `ret 8` | Yes |

---

## 5. Gaps / open

1. Product English for host field `+0xfc` and register modes 5/8 semantics beyond “passed as FUN_004dbef0 stack formals”.
2. Product name of deliver vcall `+0xc` predicate.
3. Full dual of list root `+0xe4e8` / vcall `+0x1d8` (out of body ownership).
4. Runtime / bit-exact / differential.
5. Whether Ghidra’s dropped ECX on nested `FUN_004dbef0` always equals this host (peer dual: yes for thiscall host).

**Verdict:** **accept-with-gaps**
