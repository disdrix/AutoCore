# Review B (skeptical / adversarial): `aa_005b8000` Elem0x28_CompleteDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b8000` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-F) |
| **Counterpart** | `reviews/A_aa_005b8000_Elem0x28_CompleteDtor.md` |
| **Scratch** | `tmp/a_005b8000.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is Class_009c7a1c complete dtor | **Falsified** — no vtbl install; no host offsets (+0x28 array etc.); only element fields ≤0x24 |
| 2 | This is scalar-deleting dtor | **Falsified** — no flags arg; bare RET not RET 4; never `operator_delete(this)` on ECX |
| 3 | VOG_DEBUG_STOP callee plate | **Falsified** — xrefs are vector dtor registrations only; scaffold alias discarded |
| 4 | Stride is not 0x28 | **Falsified** — all four DATA xrefs come from `0x28`-stride vector iter / ctor sites |
| 5 | Ghidra noreturn truncates body | **Falsified** — full 267 B path reaches SEH restore + `C3` |
| 6 | cdecl / stack this | **Falsified** — `mov ebp, ecx`; SEH thiscall element pattern |
| 7 | FUN_004be2a0 is unrelated free helper | **Falsified** — `mov ecx, esi` (owned) then call then `operator_delete(owned)` = complete dtor + free |
| 8 | Decompile list walk is invented | **Careful** — nested walk + dual free matches decompile; node payload offset +8 sealed; micro-order of empty-list free has decompiler confidence High but product list type open |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Element vs host/scalar role | **High** | Wrong port unit / double free |
| Stride 0x28 | **High** | Heap corruption |
| Owned@+0x24 + FUN_004be2a0 | **High** | Leak / UAF |
| Vector@+0x14 + buffer@+0x4 | **High** | Leak |
| List node payload English | **Low** | Naming / over-port |
| Product type names | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Registration (Class_009c7a1c_CompleteDtor):
_eh_vector_destructor_iterator_(arr, 0x28, count, FUN_005b8000);

// Element body (high level):
if (elem->owned@0x24) { FUN_004be2a0(owned); delete owned; }
destroy list-ptr vector @ +0x14
delete buffer @ +0x4
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Entry/epilogue hex seals SEH + bare RET. Four DATA xrefs seal shared element role.

---

## 4. Surviving contract for AutoCore

```
// Port as element dtor only (stride 0x28):
void Elem0x28_CompleteDtor(void* elem) {
  // destroy owned@+0x24 via FUN_004be2a0 + operator_delete
  // destroy list-ptr vector @ +0x14 (per-list node payload free + list free)
  // free buffer @ +0x4
}
// Used by Class_009c7a1c_CompleteDtor vector path and FUN_00494170/b0.
// Do NOT use as host complete dtor or scalar-deleting wrapper.
// Do NOT invent product plate from rejected VOG alias.
```

---

## 5. Verdict

Adversarial pass confirms A on role/ABI/stride/offsets/false-noreturn. Residual product types and list-payload English → **accept-with-gaps**.
