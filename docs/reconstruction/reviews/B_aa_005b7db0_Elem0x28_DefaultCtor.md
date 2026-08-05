# Review B (skeptical / adversarial): `aa_005b7db0` Elem0x28_DefaultCtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005b7db0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W31-L) |
| **Counterpart** | `reviews/A_aa_005b7db0_Elem0x28_DefaultCtor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is the element complete dtor | **Falsified** — only stores zeros; no free; bare zero-init; dtor is `0x005b8000` |
| 2 | This is host-level clear/rebuild | **Falsified** — body touches only ≤+0x24 element fields; sole xref is DATA ctor registration |
| 3 | VOG_DEBUG_STOP / Named_CalleeOf plate | **Falsified** — no string; only DATA from `FUN_004941b0` vector ctor |
| 4 | Stride is not 0x28 | **Falsified** — registration pairs with dtor `FUN_005b8000` at stride **0x28** (W30-Q / W29-F) |
| 5 | cdecl / stack this | **Falsified** — `mov eax, ecx`; no stack formals; bare `C3` |
| 6 | Decompile missing stores | **Falsified** — seven stores match full-body hex |
| 7 | SEH means function throws | **Falsified** — SEH frame only; no call/throw; MSVC vector-ctor pattern |
| 8 | Untouched fields mean incomplete capture | **Careful** — bytes never write +0/+0x10/+0x20; peer dtor also ignores them as free targets → intentional product layout, not truncated body |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Element default-ctor role | **High** | Wrong ctor/dtor pairing |
| Stride 0x28 | **High** | Heap corruption if port mismatches |
| Zero-offsets | **High** | Uninit free targets |
| Product type names | **Low** | Naming only |
| Untouched field English | **Low** | Over-port |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + xrefs

```
// Registration (Host_RebuildElem0x28ArrayFromMap_Inferred):
_eh_vector_constructor_iterator_(storage, 0x28, count, FUN_005b7db0, FUN_005b8000);

// Element body:
zero +4,+8,+0xc,+0x14,+0x18,+0x1c,+0x24; RET
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Full-body hex seals SEH + stores + bare RET. One DATA xref seals element-ctor role.

---

## 4. Surviving contract for AutoCore

```
// Port as element default ctor only (stride 0x28):
void Elem0x28_DefaultCtor(void* elem) {
  // zero buffer triple @ +4/+8/+0xc
  // zero list-ptr vector triple @ +0x14/+0x18/+0x1c
  // zero owned @ +0x24
}
// Used only as eh_vector_ctor_iter ctor half with Elem0x28_CompleteDtor.
// Do NOT invent VOG plate. Do NOT treat as host clear/rebuild.
```

---

## 5. Verdict

Adversarial pass confirms A on role/ABI/stride/offsets. Residual product types and untouched-field English → **accept-with-gaps**.
