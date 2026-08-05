# Review B (skeptical / adversarial): `aa_0043ec50` GuardedVector_RingAssignForward

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ec50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-J) |
| **Counterpart** | `reviews/A_aa_0043ec50_GuardedVector_RingAssignForward.md` |
| **Scratch** | `tmp/a_0043ec50.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `stdcall RET 0x1c` | **Falsified** — epilogue is plain `C3` (caller cleans) |
| 2 | Reverse / decrement walk | **Falsified** — both indices **increment** |
| 3 | Uses `begin`/`size` fields | **Falsified** — only slots@+4 + capacity@+8 |
| 4 | Has nested callees | **Falsified** — leaf; no CALL in body |
| 5 | Always stores (no skip) | **Falsified** — `if (dst_ptr != src_ptr)` gate present |
| 6 | Product name retail string | **Overstated** — inferred structural |
| 7 | Identical to `0043d390` only name | **Open residual** — same contract family; body size differs (140 vs 130 B); not byte-proven identical |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 7-arg plain RET ABI | **High** | Caller stack-corrupt |
| Forward assign CF | **High** | Insert leaves wrong residual |
| Block map `>>2` + wrap | **High** | Slot OOB |
| Self-pointer skip | **High** | Spurious write only |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | rare ring edge |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  while (src_cont,src_idx) != (end_cont,end_idx):
    map both; if ptrs differ *dst=*src; ++src; ++dst
  out = {dst_cont, dst_idx}

bytes:
  PUSH EBX/EBP/ESI/EDI; load containers
  CMP pairs → exit
  SHR 2 / capacity wrap / dword store with JE skip
  ADD 1 to both indices; JMP loop
  MOV [out],EBP; MOV [out+4],EDX; POP*; RET
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Xrefs only from insert-N / insert-range forward arms.

Sibling reverse `FUN_0043ebb0` (parent dual language) + older `RingAssignBackward` (`0043d300`) confirm this unit is the **forward** half, not a generic memmove.

---

## 4. Surviving contract for AutoCore

```
// Forward ring dword assign (insert-range / insert-N forward arms):
//   7 stack args, plain RET (caller cleans 0x1C)
//   while src cursor != stop: map, optional *dst=*src, ++src, ++dst
//   return {dst_container, final_dst_index}
// Do not unify with reverse FUN_0043ebb0 / FUN_0043d300.
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/map/self-skip; only naming + clone-delta residual → **accept**.
