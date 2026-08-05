# Review B (skeptical / adversarial): `aa_0068a620` StdVector_InsertOne_RebindIt_Elem28

| Field | Value |
|---|---|
| **Stable ID** | `aa_0068a620` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-AC) |
| **Counterpart** | `reviews/A_aa_0068a620_StdVector_InsertOne_RebindIt_Elem28.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Multi-insert API (general count) | **Falsified as this unit** — hard-coded `PUSH 1`; general count lives in `0068a1d0` |
| 2 | Same as string-vector insert-one | **Falsified** — callee is POD `InsertN_Elem28`, not basic_string family |
| 3 | Dword stride (`/4`) | **Falsified** — magic `/0x1c`, `IMUL 0x1C` |
| 4 | `RET 4` / two stack args | **Falsified** — `C2 0C 00` three stack args |
| 5 | Returns iterator in EAX | **Falsified** — void; writes `*outIt`; analyze warning is noise |
| 6 | `param_4` is a lone dword value | **Falsified** — InsertN treats it as pointer to 7 dwords |
| 7 | Scaffold `Named_CalleeOf_Named_*` plate | **Reject** — structural InsertOne_RebindIt_Elem28 |
| 8 | Index uses post-insert begin before call | **Falsified as bug claim** — index from pre-insert where; rebind uses **post**-call begin |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Insert-one + rebind shape | **High** | Wrong container port |
| ABI RET 0x0C | **High** | Stack corruption |
| Stride 0x1c | **High** | OOB index math |
| value pointer | **High** | Truncated copy |
| Product T English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Sole xref: FUN_0068ae50 @ 0068aecd (push_back slow path)
//   when size >= capacity:
//     push value; push end; lea outlocal; push out; mov ecx,vec; call 0068a620
// Fast path (room left) bypasses this unit → FUN_00688550 fill + end+=0x1c
//
// Callee W34-S sealed: InsertN POD 0x1c, RET 0x0C, max 0x9249249, 1.5× grow
```

Live decompile 2026-08-04 ≡ scaffold raw CF. Bytes seal `6A 01`, magic `/0x1c`, `C2 0C 00`. Closes W34-S residual naming of wrapper `FUN_0068a620`.

---

## 4. Surviving contract for AutoCore

```
// Port as vector<POD0x1c>::insert(where, *value) → iterator out:
void InsertOne_Rebind(
    VectorElem28* v, Elem28** outIt, Elem28* where, const Elem28* val)
{
  uint32_t index = empty(v) ? 0 : (where - begin) / 0x1c;
  InsertN(v, where, 1, val);          // may realloc
  *outIt = begin' + index;            // element-pointer form
}
// Do NOT invent multi-count here; do NOT unify with basic_string insert-one.
// RET 0x0C thiscall.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI/CF/stride/count=1/rebind. Rejects scaffold Named_* and dword/string aliases. Residual product T → **accept-with-gaps**.
