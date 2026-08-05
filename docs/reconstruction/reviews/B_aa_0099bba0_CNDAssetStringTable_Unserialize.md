# Review B (skeptical / adversarial): `aa_0099bba0` CNDAssetStringTable_Unserialize

| Field | Value |
|---|---|
| **Stable ID** | `aa_0099bba0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W34-J) |
| **Counterpart** | `reviews/A_aa_0099bba0_CNDAssetStringTable_Unserialize.md` |
| **Scratch** | `tmp/a_0099bba0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Function is Serialize | **Falsified** — plate `CNDAssetStringTable::Unserialize`; serialize lives at `0x0099b8e0` |
| 2 | void / noreturn (Ghidra delete warning) | **Falsified** — `B0 01` + `C2 0C 00` epilogue after delete |
| 3 | thiscall ECX=host | **Falsified** — three stack formals, RET 12; EBP used as stream |
| 4 | Only loads strings (no pyramids) | **Falsified** — pyramid count log + `FUN_00430540`/`FUN_00430600` + nested loops in hex |
| 5 | Decompiler CF is complete authority | **Weakened** — many unreachable-block warnings; nested schema Med conf only |
| 6 | Returns 0 on empty | **Falsified** — success path always sets AL=1 after cleanup (including empty begin) |
| 7 | Scaffold FUN name is product | **Rejected** — rename to plate `CNDAssetStringTable_Unserialize` |
| 8 | String intern is optional | **Falsified** — every string iteration calls `FUN_00989e00` before push_back |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Product Unserialize plate | **High** | Wrong system ownership |
| RET 12 + AL=1 | **High** | ABI crash / wrong success |
| String-table stage order | **High** | Corrupt table load |
| Pyramid nested row layout | **Med** | Silent schema mismatch on port |
| Host object field map | **Open** | Wrong member writes |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + serialize twin

```
// Serialize (0x0099b8e0) plates:
"CNDAssetStringTable::Serialize"
"string table size =%u"
"pyramids =%u"

// Unserialize (0x0099bba0) plates:
"CNDAssetStringTable::Unserialize"
"string table size =%u"
"pyramids =%u" / "pyramids = %u"

// Direction:
Serialize: host → stream write (vtbl+0x18)
Unserialize: stream read (vtbl+0x14) → host
```

Caller `FUN_0099c1c0` constructs local table (`PTR_FUN_00a983b4`) and invokes unserialize with stream `param_1`.

---

## 4. Surviving contract for AutoCore

```
// Port outline:
bool CNDAssetStringTable::Unserialize(Stream& in) {
  // log plate
  uint32_t n = in.ReadU32();
  for (uint32_t i = 0; i < n; ++i) {
    std::string s = in.ReadCString();
    InternOrLookup(s);
    // stage / attach per retail host rules
  }
  uint32_t nPy = in.ReadU32();
  ResizePyramids(nPy); // elem stride 0x10 in retail
  // nested pyramid/row fill + name→index via case-insensitive compare
  return true;
}
// Do not treat as Serialize; do not trust Ghidra noreturn; do not invent row POD without dual of nested helpers.
```

---

## 5. Verdict

Adversarial pass confirms product plate, ABI, return-1, and string-table stage. Nested pyramid schema + host layout remain open → **accept-with-gaps**.
