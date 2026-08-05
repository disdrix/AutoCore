# Review B (skeptical / adversarial): `aa_0096f530` RefCountedPtr3Flags_DefaultCtor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0096f530` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W35-G) |
| **Counterpart** | `reviews/A_aa_0096f530_RefCountedPtr3Flags_DefaultCtor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Function is truly `void` (Ghidra) | **Falsified** — `mov eax,ecx` leaves this in EAX; same pattern as sealed `0096ef70` |
| 2 | Same as `RefCountedPtr_DefaultCtor` (`0096ef70`) | **Falsified** — that unit is 9 B pointer-only; this is 16 B with +4/+5/+6 zeros |
| 3 | Full 8-byte `memset`/zero of object | **Falsified** — byte +7 never written |
| 4 | Not a ctor (re-null mid-life helper) | **Unlikely primary** — used as vector-ctor element ctor and placement in host ctors; may also re-init |
| 5 | Three bytes are a single 24-bit field | **Open / naming only** — stores are three separate byte MOVs; no product plate |
| 6 | Peer dtor pairing is coincidence | **Rejected** — `_eh_vector_constructor_iterator_(…,8,2,FUN_0096f530,FUN_0096f510)` binds them |
| 7 | Classification "leaf" means unused | **Falsified** — 28 xrefs / 16 named callers |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Zero dword + 3 flag bytes | **High** | Wrong host init |
| ECX this / EAX return | **High** | Lost this |
| Distinct from `0096ef70` | **High** | Merged types |
| Refcounted payload via dtor | **High** | Wrong release policy |
| Flag English / +7 pad | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes + callers

```
// Body hex @ 0x0096f530 (16 B):
// 8B C1 | 33 C9 | 89 08 | 88 48 04 | 88 48 05 | 88 48 06 | C3

// Peer dtor 0x0096f510 (context):
// 8B 09 | 85 C9 74 0B | 83 41 04 FF | 75 05 | 8B 01 FF 60 08 | C3
//   *this → ecx; if non-null: --refcount@+4; if 0: jmp [vtbl+8]

// ParticleFluidPhase (0x004c0640): FUN_0096f530 @ +0x84 and +0x8c (8-byte stride)
// FUN_00457720: vector_ctor element size 8, count 2, ctor=0096f530, dtor=0096f510
```

Live decompile 2026-07-29 ≡ raw 2026-07-23 CF. Full-body hex seals return path and partial zero.

---

## 4. Surviving contract for AutoCore

```
// Port as default ctor for 8-byte handle shell:
struct Handle {
  void* ptr;      // +0
  uint8_t f0,f1,f2; // +4..+6
  // +7 pad not written
};
Handle* ctor(Handle* self) {
  self->ptr = nullptr;
  self->f0 = self->f1 = self->f2 = 0;
  return self;
}
// Do NOT merge with RefCountedPtr_DefaultCtor (pointer-only).
// Do NOT invent flag meanings. Pair release with peer dtor 0096f510 when porting hosts.
// Ignore Ghidra void return.
```

---

## 5. Verdict

Adversarial pass confirms A on stores/ABI/size/distinction/peer-dtor role. Residual flag English + +7 pad → **accept-with-gaps**.
