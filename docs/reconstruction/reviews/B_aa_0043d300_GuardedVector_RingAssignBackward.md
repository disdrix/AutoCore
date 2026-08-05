# Review B (skeptical / adversarial): `aa_0043d300` GuardedVector_RingAssignBackward

| Field | Value |
|---|---|
| **Stable ID** | `aa_0043d300` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W28-C) |
| **Counterpart** | `reviews/A_aa_0043d300_GuardedVector_RingAssignBackward.md` |
| **Scratch** | `tmp/a_0043d300.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | `stdcall RET 0x1c` | **Falsified** — epilogue is plain `C3` |
| 2 | Forward memmove only | **Falsified** — both indices **decrement** |
| 3 | Uses `begin`/`size` fields | **Falsified** — only `+0x04` slots + `+0x08` capacity |
| 4 | Has nested callees | **Falsified** — leaf; no CALL in body |
| 5 | Product name retail string | **Overstated** — inferred structural |
| 6 | Decompiler invents wrap | **Falsified** — wrap compare present in bytes |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 7-arg plain RET ABI | **High** | Caller stack-corrupt |
| Reverse assign CF | **High** | Erase leaves wrong residual |
| Block map `>>2` + wrap | **High** | Slot OOB |
| Product English | **Inferred** | Naming only |
| Runtime | **Open** | rare ring edge |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  while (param_2,param_3) != (param_4,param_5): param_5--, param_7--, *dst=*src
  out = {param_6, param_7}

bytes:
  MOV EAX,[esp+0x1c]  ; param_7
  CMP stop vs src pair → exit
  DEC indices; capacity wrap; dword store
  MOV [out+4],EAX; MOV [out],EDX; RET
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Xrefs only from erase reverse arm + two assign helpers.

Sibling `FUN_0043d390` walks **forward** — confirms this unit is the reverse half, not a generic memmove.

---

## 4. Surviving contract for AutoCore

```
// Reverse ring dword assign (erase shorter-prefix / packing):
//   7 stack args, plain RET
//   while src cursor != stop: --src, --dst, *dst = *src (capacity-wrapped blocks)
//   return {dst_container, final_dst_index}
```

---

## 5. Verdict

Adversarial pass **confirms** A on ABI/CF/map; only naming residual → **accept**.
