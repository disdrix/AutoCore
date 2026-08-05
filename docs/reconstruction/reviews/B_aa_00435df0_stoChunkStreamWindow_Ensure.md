# Review B (skeptical / adversarial): `aa_00435df0` stoChunkStreamWindow_Ensure

| Field | Value |
|---|---|
| **Stable ID** | `aa_00435df0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W18-A) |
| **Counterpart** | `reviews/A_aa_00435df0_stoChunkStreamWindow_Ensure.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` only (plus xrefs for role). No `disassemble_bytes`. Own VA `0x00435df0` only.

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | cdecl / no stack cleanup | epilogues are `c2 04 00` | **Falsified** — **`ret 4`**, one stack arg |
| 2 | Pure refill without changing base/cursor | all arms write base + cursor=0 | **Falsified** — **reposition** |
| 3 | Always memmove | Arm C has no memmove | **Falsified multiplicity** — three arms |
| 4 | Returns void / ignores errors | ReadHeader16 `if (hr < 0)` | **Falsified as port contract** — **EAX status** (decomp void is surface) |
| 5 | `pSource` is a function pointer | `*(int*)*param_1` then +4/+0x14 | **Falsified** — **object* with vtbl** |
| 6 | Window buffer at `param_1[0]` | buffer at `+0x18` | **Falsified** |
| 7 | Capacity is `available` | capacity is `[4]` / `+0x10` | **Falsified** |
| 8 | Single-purpose gfxBody helper (parent-seed) | 50+ stoChunk + other xrefs | **Falsified** — **shared stream ensure** |
| 9 | Clean should invent file-API names as proven PDB | no strings in body | **Open English** — structural Seek/Read only |
| 10 | Three-rep diverges | live ≡ raw ≡ arms | **Falsified** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + ret 4 + absPos | **High** | stack corruption on port |
| Three-arm slide/full CF | **High** | wrong window after partial seek |
| cursor cleared; base=absPos | **High** | ReadHeader16 post-check fails |
| available = min(cap, end-base) | **High** | over-read |
| EAX = last Read | **High** | silent truncation |
| streamEnd / Seek/Read English | **Probable / Inferred** | doc-only mislabel |
| Runtime / bit-exact | **Open** | shipping image |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  if (base <= abs && abs < base+avail) { /* A memmove keep; Seek; Read tail */ }
  else if (base <= cap+abs)           { /* B memmove shift; Seek; Read gap */ }
  else                                { /* C Seek; Read full */ }

bytes:
  prologue 53 55 56 8B F1 … 57 8B 7C 24 14
  memmove via FF 15 2C 65 9C 00
  exits: C2 04 00 ×3
  pad: CC…
```

Path-C decomp `stack0xfffffffc` is the **min(capacity, streamEnd-base)** temp — not a real third pointer field.

**No conflict** on owned CF. Product symbol open.

---

## 4. Surviving contract for AutoCore

```csharp
// stoChunkStreamWindow_Ensure @ 0x00435df0
// retail: ECX = window, stack absPos, ret 4; EAX = Read hr

int Ensure(StoStreamWindow w, int absPos)
{
  // Re-anchor base=absPos, cursor=0, slide or full fill from pSource.
  // Do NOT treat as no-op when already positioned — arms may still Seek/Read.
  // Fail only when returned hr < 0 (callers also re-check available).
}
```

Port rules:

- Keep **three arms**; do not collapse to always-full-read (performance + overlap semantics).
- Do not invent error checks on Seek return (retail discards).
- Sibling readers pass **`base+cursor`**, not a free-form “bytes needed” count.

---

## 5. Open questions

1. PDB / stoChunk product name for ensure helper.
2. Who initializes `streamEnd` (+0x14) and capacity (+0x10).
3. Whether any caller depends on available==0 success path.

**Verdict:** **accept-with-gaps**
