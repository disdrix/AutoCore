# Review B (skeptical / adversarial): `gfxIndexBufferImpl_Serialize` @ `0x00988a10`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00988a10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00988a10_gfxIndexBufferImpl_Serialize.md` |
| **Verdict** | **accept-with-gaps** on CF/chunk envelope; **needs-more-evidence** on callee wire body |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Always writes version-2 INDX | **Survives** — BeginChunk hardcodes tag + version 2 |
| 2 | Plate body layout (id/size/count/count2/data) is in *this* function | **Overstated** — body writes are FUN_* callees; plate is prior art / sibling evidence |
| 3 | Triangle-list topology encoded in chunk | **Falsified as chunk field** — plate says topology fixed, not stored |
| 4 | Lock always succeeds | **Falsified** — null device or failed lock → status −1 |
| 5 | Unlock always calls device Unlock | **Falsified** — only if deviceIB and vtbl non-null; underflow logs and clamps count |
| — | Param names / FUN_* production-ready | **Overstated** |
| — | Runtime verified | **Falsified** — open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| INDX / XDNI + version 2 envelope | High | Wrong geo export format |
| Device lock/unlock around write | High | GPU resource hazard / bad import |
| Status −1 vs FUN_0044ed10 | High | Silent bad assets |
| FUN_* body writers exact layout | Medium | Mismatched Autocore .geo writer |
| Clean is CF-preserving scaffold | High | Low for map use; high if bit-exact claim |

---

## 3. Surviving contract for AutoCore

```
gfxIndexBufferImpl_Serialize(this) -> int:
  BeginChunk(0x494e4458 /*INDX*/, 2)
  if this->deviceIB(+0x10):
    lock = Lock(count-ish@+0x18, indexSize@+0x1c, 0x810)
    if lock: write-raw(indexSize, count)
  write-header-helpers()
  status = (lock==0) ? -1 : write-status()
  Unlock deviceIB if present (lockCount[3]; vtbl+0x30)
  if status < 0: log fail
  EndChunk; return status
```

---

## 4. Open questions

1. Map FUN_00743be0 / FUN_00734640 / FUN_0044ed10 to named gfx helpers.
2. Confirm indexSize field is `this+0x1c` and count `this+0x18` against Unserialize sibling `0x00989030`.
3. No runtime / retail dump re-check in this dual.

**Verdict:** **accept-with-gaps** on CF; safe as .geo INDX writer map — do not treat unresolved FUN_* as sealed codecs.
