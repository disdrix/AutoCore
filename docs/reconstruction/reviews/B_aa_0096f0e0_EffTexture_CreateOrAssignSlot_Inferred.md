# Review B (skeptical / adversarial): `aa_0096f0e0` EffTexture_CreateOrAssignSlot_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096f0e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-H) |
| **Counterpart** | `reviews/A_aa_0096f0e0_EffTexture_CreateOrAssignSlot_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Pure create (no replace) | **Falsified** — prior `*slot` is ref-released before store |
| 2 | Same as RefCountedPtr3Flags family (`0096f510`) | **Falsified** — this unit uses ref@**+8** / iface@**+4**; 3Flags uses vtbl@**+0** / ref@**+4** |
| 3 | `this` is a fat object with many fields | **Falsified** — ECX is a **slot pointer** only (`mov edi,ecx`; single `*edi` store) |
| 4 | Factory formals match Ghidra `FUN_0096e9f0(1 arg)` | **Rejected for callee** — this unit **pushes five** args; callee under-declared; **bytes of this unit win** for its push count |
| 5 | All six stack params are live | **Partially falsified** — one dword loaded to EBX and never used |
| 6 | Log path is non-fatal continue | **Falsified** — returns `0xffffffff` without assigning slot |
| 7 | Scaffold name `Named_effTexture_0096f0e0` is sufficient | **Rejected** — role is create-or-assign, not the texture class itself |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Create-or-assign + refcount CF | **High** | Leaked textures / double free |
| ECX slot / RET 0x18 / 0\|-1 | **High** | Wrong call sites |
| Plate path + message | **High** | Mis-sourced unit |
| Payload +4/+8 layout | **High** | Merged with 3Flags dtor |
| Factory arg English | **Low** | Naming only until factory dual |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + callers

```
// Body 124 B @ 0x0096f0e0; dual RET 0x18 success/fail
// Plates: 0x00a9ed50 path, 0x00a9ed24 "Failed to create instance of texture."
// Caller 0x0048ed00: two creates (full dims → env+0xDC; half dims → env+0xE0)
// Live decompile 2026-08-04 ≡ raw 2026-07-23 CF
```

Release path mirrors `FUN_0096efd0` layout but **without** clearing the slot before overwrite (overwrite stores new immediately after release).

---

## 4. Surviving contract for AutoCore

```
// Port as effect-texture create-or-assign:
//   ECX = payload**; six stack args; RET 0x18
//   factory → on null: log + return -1
//   else: acquire new (ref@+8; first-use vtbl[+4] on +4)
//         release old (ref@+8; final vtbl[+8] on +4)
//         *slot = new; return 0
// Do NOT merge with RefCountedPtr3Flags_Dtor (0096f510).
// Do NOT invent factory arg product names without 0096e9f0 dual.
// Ignore scaffold Named_effTexture_* alias.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, plates, create-or-replace CF, and layout distinction. Residual factory arg English + virtual names → **accept-with-gaps**.
