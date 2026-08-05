# Review B (skeptical / adversarial): `aa_007b7df0` FUN_007b7df0

| Field | Value |
|---|---|
| **Stable ID** | `aa_007b7df0` |
| **VA** | `0x007b7df0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_007b7df0_FUN_007b7df0.md` |
| **Tools** | Ghidra decompile + full-body `read_memory` (no Launcher) |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Leave is a critical-section unlock | Symmetry with "enter" naming | **Falsified** — COM Release + refcount only |
| 2 | Always Releases on every call | Nested ensures | **Falsified** — only when refcount hits 0 |
| 3 | Releases even in XML mode | `DAT_00d1793c` | **Falsified** — `jnz` skips release block when flag ≠ 0 |
| 4 | Order `+0x24` then `+0x28` | Typical construction order | **Falsified** — asm Releases **`+0x28` first** |
| 5 | Returns status of Release | COM hr | **Falsified** — `xor eax,eax` always |
| 6 | Safe if refcount already 0 | `add [esi+0x20],-1` | **Risk open** — underflow not guarded; would treat as non-zero after wrap until hits 0 again |
| 7 | Clean scaffold is modernization-ready | Scaffold types | **Weak** — behavior OK; names/types still FUN/DAT |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 64-byte leaf body complete | **High** | Missed side effects |
| Ensure pairing with `FUN_007e1d80` | **High** | Connection leak / crash |
| XML mode leave is no-op teardown | **High** | Double-free if wrongly released |
| Underflow guard | **None in binary** | Port must not unpaired-leave |

---

## 3. Minimal contract

```
void DBReader_Leave(DbReaderCtx* this) {
  if (--this->refcount != 0) return;
  if (g_bXmlDataMode) return;          // DAT_00d1793c
  ReleaseNull(&this->pObj_0x28);       // vtbl+8
  ReleaseNull(&this->pObj_0x24);
  this->bConnected = 0;                // byte at +0
}
// Always returns 0 in retail
```

---

## 4. Open questions

1. Who sets `DAT_00d1793c` (boot flag vs config)?
2. Can leave run on a different thread than enter (would need external lock — **not present here**)?

**Verdict:** **accept-with-gaps**
