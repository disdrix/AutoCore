# Review B (skeptical / adversarial): `gfxVertexBufferImpl_Serialize` @ `0x009994c0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_009994c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_009994c0_gfxVertexBufferImpl_Serialize.md` |
| **Verdict** | **accept-with-gaps** on chunk envelope; **needs-more-evidence** on `this` register + FUN_* body |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Writes version 1 or 2 VERT | **Falsified** — BeginChunk hardcodes version **3** only |
| 2 | Decl body fully inlined here | **Falsified** — nested FUN_00746d40 / FUN_00746f90 |
| 3 | Device lock always required | **Falsified** — gated on this+0x10 |
| 4 | Signature is free-func with no this | **Overstated** — decompiler lost this as unaff_EDI |
| 5 | Unreachable block changes semantics | **Unproven** — warning only; CF still matches plate |
| — | Runtime verified | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| VERT/TREV + v3 envelope | High | Wrong .geo export |
| Offsets +0x10/+0x14/+0x18/+0x24 | High | Wrong object layout port |
| Nested DECL + raw data write | High | Mesh corruption |
| unaff_EDI = this | Medium | Wrong calling convention in Autocore |
| FUN_* bit layout | Medium | Incompatible assets |

---

## 3. Surviving contract for AutoCore

```
gfxVertexBufferImpl_Serialize(this /*EDI residual*/) -> int:
  BeginChunk(0x56455254 /*VERT*/, 3)
  if device@+0x10: lock(stride@+0x14, count@+0x18, mode=4); maybe write raw helper
  serialize-header helpers
  status = serialize-DECL / nested
  if ok: write DECL state@+0x24; write verts(count@+0x18)
  if write fail: log; cleanup; EndChunk; return -1
  EndChunk; return status
```

---

## 4. Open questions

1. Confirm thiscall / register this against callers.
2. DECL element packing (plate: u8 type/stream/usage/index × count).
3. No live serialize capture.

**Verdict:** **accept-with-gaps** — use as VERT v3 writer map; seal FUN_* in follow-up duals.
