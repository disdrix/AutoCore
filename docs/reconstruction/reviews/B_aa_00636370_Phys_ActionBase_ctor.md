# Review B (skeptical / adversarial): `aa_00636370` Phys_ActionBase_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00636370` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (W17-P) |
| **Counterpart** | `reviews/A_aa_00636370_Phys_ActionBase_ctor.md` |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `read_memory` (+ xrefs for caller claims).

---

## 1. Claims under attack

| # | Claim | Result |
|---|---|---|
| 1 | This is VehicleAction's full ctor | **Falsified** — VehicleAction_ctor @ `0x00597f90` calls this then stamps class fields/vtbls |
| 2 | Decompiler `FUN_00507290(param_1)` means append on the action object | **Falsified** — bytes keep ECX=host; list lives at **host+0x94** (actions are ~0x48, no +0x9c) |
| 3 | Host is always required | **Falsified** — `jz` skips register/addref when host==0 |
| 4 | Intermediate vtbl `0x009e3a68` remains final | **Falsified** — immediately overwritten by `0x009e5e78` |
| 5 | Writes size/flags at +4 | **Falsified** — body never stores +4 |
| 6 | `ret` without stack cleanup | **Falsified** — `c2 04 00` pops one arg |
| 7 | Parent-seed CVOGHBAIDriver name describes purpose | **Falsified** — callers are VehicleAction / flipper / `00658bf0` |
| 8 | Primary and secondary vtbls are the same pointer | **Falsified** — `0x009e39f4` vs `0x009e5e78` |
| 9 | Addref increments **action** refcount again after seed | **Falsified** — second `+6` add is on **host** (`[esi+0x18]`) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Dual vtbl + refcount base | **High** | derived objects missing base MI layout |
| Optional host register/addref | **High** | leak or double-free / missing island link |
| FUN_00507290 host-in-ECX | **High** | append into wrong object → heap corruption |
| Not full VehicleAction init | **High** | missing thr/steer/mode fields in ports |
| Product English "hkAction" | **Medium** | naming only; layout still portable |

---

## 3. Cross-check against raw + bytes

```
self+6 = 1
self+8 = intermediate_secondary
self+0xc = 0
self+0x14 = 0
*self = primary_base
self+8 = final_secondary
self+0x18 = host
if host:
  append self onto host.vector(+0x94)
  host.refcount(+6)++
return self
```

Any clean that:

- calls `FUN_00507290(self)` with self-as-this, or
- treats intermediate secondary as final, or
- folds VehicleAction DAT stamps here

is **wrong**.

---

## 4. Surviving contract for AutoCore

```c
// Port of Phys_ActionBase_ctor (client physics action base)
struct ActionBase {
  void *vtbl_primary;     // +0x00
  // +0x04 size/flags often from allocator — not set here
  uint16_t refcount;      // +0x06
  void *vtbl_secondary;   // +0x08
  uint32_t z_0c;          // +0x0c
  // +0x10 untouched
  uint32_t z_14;          // +0x14
  void *host;             // +0x18
};

ActionBase *Phys_ActionBase_ctor(ActionBase *self, void *host) {
  self->refcount = 1;
  self->vtbl_secondary = &kSecondaryIntermediate; // then immediately:
  self->z_0c = 0;
  self->z_14 = 0;
  self->vtbl_primary = &kPrimaryBase;
  self->vtbl_secondary = &kSecondaryFinal;
  self->host = host;
  if (host) {
    Host_AppendActionPtr(host, self);  // FUN_00507290
    Host_AddRef(host);                 // *(u16*)(host+6)++
  }
  return self;
}
// Derived ctor overwrites vtbl_primary / vtbl_secondary with class tables.
```

---

## 5. Open questions

1. Exact Havok class name / whether custom wrapper around hkAction.
2. Host type identity: always same C++ type across the 3 callers?
3. Sibling dtor symmetry (`FUN_00636290`) — release host, restore base vtbls.
4. Whether host vector at +0x94 is island action list or a different owner list (createVehicleAction also has separate `FUN_0055fe50` world register — **different** path).

**Verdict:** **accept-with-gaps**
