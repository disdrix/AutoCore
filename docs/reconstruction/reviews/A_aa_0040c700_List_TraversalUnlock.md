# Review A (reconstruction fidelity): `aa_0040c700` List_TraversalUnlock

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040c700` |
| **VA** | `0x0040c700`–`0x0040c715` |
| **Canonical name (Ghidra)** | `FUN_0040c700` |
| **Proposed name** | `List_TraversalUnlock` |
| **Review date** | `2026-08-04` (WQ9D-E OWN-ONLY dual A) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_0040c700_List_TraversalUnlock.md` |
| **System** | client::list (skill status path is one consumer) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

Shared **traversal unlock** for the CS list family sealed by `List_TraversalLock` (`0x004294f0`):

1. If `*(list+0x28) == 0` → return (already unlocked; **no** LeaveCS).
2. Else clear `*(list+0x28) = 0`, then `LeaveCriticalSection(list+4)`.

No node walk, no free, no throw. Exact inverse of TraversalLock success path (EnterCS then flag=1).

Appears on skill residual path via `Client_RecvSkillStatusEffect` (×2 call sites) among **17** total xrefs.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` / `analyze_function_complete` @ `0x0040c700` |
| Bytes | `read_memory` 32 B — `cmp [ecx+0x28],0` / clear / `add ecx,4` / IAT LeaveCS / `ret` / `CC` |
| Pair lock | dual `A/B_aa_004294f0_List_TraversalLock` — string `"List Error!  TraversalLock Call Stack"`; EnterCS(`+4`); flag `+0x28=1` |
| Sibling iter | `List_IterateNext` (`0x004022a0`) — requires flag; TryEnter(`+4`) |
| Callers | `Client_RecvSkillStatusEffect` + list/UI helpers (17 UNCONDITIONAL_CALL) |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_0040c700` |

**Not performed:** `disassemble_bytes`, Launcher, runtime, parent ledgers.

---

## 3. Signature

```c
void __fastcall List_TraversalUnlock(void *list);
// ECX = list*; plain ret; void
```

| Item | Evidence |
|---|---|
| Convention | `ret` @ `0x0040c714`; ECX this |
| Flag @ `+0x28` | `cmp byte [ecx+0x28],0` |
| CS @ `+4` | `add ecx,4; push ecx; call [IAT LeaveCriticalSection]` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Flag==0 → early return | **Yes** |
| Flag=0 then LeaveCS(+4) | **Yes** |
| No EnterCS / no iterate / no free | **Yes** |
| Inverse of TraversalLock layout | **Yes** |

### Layout (sealed)

| Off | Role |
|----:|------|
| `list+4` | `CRITICAL_SECTION` |
| `list+0x28` | traversal-lock flag |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Unlock CF + offsets | **High** | bytes + decompile |
| Pair of TraversalLock | **High** | identical layout; registry lock sealed |
| Name `List_TraversalUnlock` | **High** (role) | lock string seals “TraversalLock”; unlock is role dual |
| Product list class RTTI | **Open** | shared family |
| Skill-only helper | **Falsified** | broad xrefs |

---

## 6. Gaps / open

1. Product/PDB list class name.  
2. Whether some sites still inline LeaveCS instead of this helper.  
3. Runtime / bit-exact.

**Verdict:** **accept** — CF/ABI/pair High; product class name open only.
