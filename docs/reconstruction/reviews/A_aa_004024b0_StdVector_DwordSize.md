# Review A (reconstruction fidelity): `aa_004024b0` StdVector_DwordSize

| Field | Value |
|---|---|
| **Stable ID** | `aa_004024b0` |
| **VA** | `0x004024b0` |
| **Canonical name** | `StdVector_DwordSize` |
| **Prior scaffold** | `FUN_004024b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_004024b0_StdVector_DwordSize.md` |
| **System** | containers (shared) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept** |

---

## 1. Purpose

Thin **`vector<uint32_t|T*>::size()`** helper (`__fastcall` / thiscall on host):

```
if (*(this+4) == 0) return 0;          // begin null
return (*(this+8) - *(this+4)) >> 2;   // (end - begin) / 4
```

Layout: **begin @ +4**, **end @ +8** (capacity not read). Leaf — no callees.

Multi-domain callers (sample): `Client_UpdateNpcInteractIcons` (`0x0091b8d0`), `FUN_004bb970`, `FUN_008a79b0`, `FUN_008a8770`, `FUN_008be900`, `FUN_0092c080`, `FUN_009440e0`.

**Not** capacity, not floater 0x38 size, not skill-set 0x18 size (`SkillSet_GetEntryCount` @ `0x00402d80`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x004024b0` |
| Bytes | `read_memory` 32 B — `8B 51 04` / `C1 F8 02` / plain `C3` |
| Callers | `get_function_callers` (7+) |
| Raw / clean | `aa_004024b0_*` |

**Not performed:** Launcher, runtime, ledgers.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| begin @ +4, end @ +8 | **Confirmed** | `mov edx,[ecx+4]`, `mov eax,[ecx+8]` |
| Null begin → 0 | **Confirmed** | `test edx,edx` / `xor eax,eax` |
| Size = `(end-begin)>>2` | **Confirmed** | `sub` + `sar eax,2` |
| No stack args / plain ret | **Confirmed** | `C3` |
| Element width 4 | **Confirmed** | sar 2 |
| Leaf | **Confirmed** | no CALL |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Null begin early 0 | Yes |
| Else arithmetic size | Yes |
| No invent capacity field | Yes |

```c
int StdVector_DwordSize(void *vec) {
  int begin = *(int *)((char *)vec + 4);
  if (begin == 0) return 0;
  return (*(int *)((char *)vec + 8) - begin) >> 2;
}
```

---

## 5. Gaps / open

1. Host type varies by caller (generic helper).
2. Whether any caller passes non-vector with same offsets (contract risk = caller dual).

**Verdict:** **accept**
