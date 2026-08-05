# Review B (skeptical / adversarial): `aa_0043ebb0` GuardedVector_RingAssignBackwardChecked

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043ebb0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W33-K) |
| **Counterpart** | `reviews/A_aa_0043ebb0_GuardedVector_RingAssignBackwardChecked.md` |
| **Scratch** | `tmp/a_0043ebb0.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Identical to `0043d300` RingAssignBackward | **Partial** — same reverse walk; **differs** by self-guard + out store order |
| 2 | `stdcall RET 0x1c` | **Falsified** — epilogue is plain `C3` |
| 3 | Forward memmove only | **Falsified** — both indices **decrement** |
| 4 | Uses begin/size fields | **Falsified** — only `+0x04` slots + `+0x08` capacity |
| 5 | True void return | **Falsified** — `MOV EAX,out` before stores; EAX survives |
| 6 | Has nested callees | **Falsified** — leaf; no CALL in body |
| 7 | Product name retail string | **Overstated** — inferred structural |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 7-arg plain RET ABI | **High** | Caller stack-corrupt |
| Reverse assign CF | **High** | Insert mid-range wrong residual |
| Self-alias skip | **High** | only self-overlap edge |
| Out pair / EAX return | **High** | iterator rebind wrong |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | rare ring edge |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  while (p2,p3) != (p4,p5): p5--, p7--, if dst!=src *dst=*src
  *out = {p6, p7}

bytes:
  DEC src_i / dst_i; capacity wrap; CMP dest,src; conditional dword store
  MOV EAX,out; MOV [EAX],dst_c; MOV [EAX+4],dst_i; RET
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Callers: InsertN_Thiscall (`0043e352`), `0043df90`, InsertRange (`0044e4bd`), `005441d0`.

Do **not** collapse with `0043d300` (no self-guard) or forward walker `0043d390` / `0043ec50`.

---

## 4. Surviving contract for AutoCore

```
// Reverse ring dword assign with address self-guard:
//   7 stack args, plain RET, returns out in EAX
//   while src cursor != stop: --src, --dst; if dst!=src *dst=*src
//   out = {dst_container, final_dst_index}
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/map/self-guard/return; only naming residual → **accept**.
