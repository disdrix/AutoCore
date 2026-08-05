# Review B (skeptical / adversarial): `Object_FwriteColorFields_Inferred` / `FUN_005e1fc0` @ `0x005e1fc0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_005e1fc0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-J) |
| **Counterpart** | `reviews/A_aa_005e1fc0_Object_FwriteColorFields_Inferred.md` |
| **Verdict** | **accept-with-gaps** on CF/ABI/offsets; reject decompiler “fwrite FILE* locals” reading |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Pure color **writer into object** (W28-E shorthand “color field write helper”) | **Overstated** — body **reads** float colors from object and **writes stream**; does not store colors into `this` |
| 2 | Locals `local_8`/`local_4` are `FILE*` copies written back | **Falsified** — stack slots hold **packed u8×4** after `FUN_00973820`; final `fwrite` dumps those 4-byte colors |
| 3 | cdecl / plain `ret` | **Falsified** — **`ret 4`** thiscall with one stack arg |
| 4 | `FUN_00973820(src)` only (no dest) | **Falsified** — ECX dest = stack color (W28-E seal); push `this+off` as float* src |
| 5 | Has direct code callers | **Falsified** — only **vtable DATA** xref `@ 0x009dc8e8` |
| 6 | Independent of base serialize | **Falsified** — always calls `thunk_FUN_005a61d0` first |
| 7 | Product name sealed | **Open** |
| 8 | Runtime / bit-exact | **Open** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| thiscall + ret 4 + FILE* stream | **Confirmed** | stack imbalance |
| Offsets `+0x170` / `+0x174` / `+0x184` | **Confirmed** | wrong field map on port |
| Pack-then-fwrite (not fwrite floats) | **Confirmed** | stream layout mismatch vs deserialize twin |
| “Writes colors into object” | **Rejected** | opposite dataflow |
| Class / product method name | **Open** | docs only |
| Runtime golden | **Open** | |

---

## 3. Cross-check against raw + bytes

Entry/exit (`read_memory`):

```
83 EC 08  53 56 57  8B 7C 24 18  57  8B F1  E8 …   ; this→esi, file→edi, call base
…
C2 04 00  CC CC CC                                   ; ret 4
```

Pack site pattern:

```
lea ecx, [esi+0x174]   ; float* src
push ecx
lea ecx, [esp+…]       ; u8* dest local
call FUN_00973820      ; ret 4
```

Deserialize neighbor `FUN_005e2040` reads `+0x170` then unpacks into `+0x174`/`+0x184` — **confirms stream layout**, not an in-place color setter.

---

## 4. Surviving contract for AutoCore

```
// thiscall; stack FILE*; ret 4; void
void Object_FwriteColorFields(Object* self, FILE* f):
  BaseSerialize(self, f)           // thunk_FUN_005a61d0
  fwrite(&self->field_170, 4, 1, f)
  pack255(tmpA, self->colorA_174)  // FUN_00973820
  pack255(tmpB, self->colorB_184)
  fwrite(&tmpA, 4, 1, f)
  fwrite(&tmpB, 4, 1, f)
```

Do **not** treat as a mutator of object colors. Do **not** fwrite the float4s raw. Do **not** drop the base-serialize call. Preserve **ret 4**.

---

## 5. Falsification notes

### 5.1 “Color field write helper”

W28-E listed this as a pack caller with “color field write” shorthand. Body direction is **object → stream**. Twin `FUN_005e2040` is stream → object.

### 5.2 Decompiler FILE* locals

Raw shows `local_8 = param_2; local_4 = param_2; fwrite(&local_*)`. Bytes show those slots are pack destinations; stream is kept in EDI/`[esp+…]` separately. Prefer bytes.

### 5.3 Missing code xrefs

Absence of CALL xrefs is expected for **vtable** methods. Slot `@ 0x009dc8e8` seals dispatch existence.

---

**Verdict:** **accept-with-gaps** — sealed stream color-extension serialize; reject decompiler local typing and “write into object” reading.
