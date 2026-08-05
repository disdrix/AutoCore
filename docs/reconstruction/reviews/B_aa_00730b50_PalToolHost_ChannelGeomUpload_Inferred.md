# Review B (skeptical / adversarial): `aa_00730b50` PalToolHost_ChannelGeomUpload_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00730b50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (OWN-ONLY W37-U) |
| **Counterpart** | `reviews/A_aa_00730b50_PalToolHost_ChannelGeomUpload_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | ECX-thiscall method | **Falsified** — 2 stack args; `RET 8`; not thiscall |
| 2 | Function *is* gfxDeviceVB method | **Falsified** — string is unlock error plate path; role is host channel upload |
| 3 | Single channel / no index | **Falsified** — `param_2` indexes host slots; caller passes 0 and 1 |
| 4 | Bare scaffold name sufficient | **Careful** — keep structural `_Inferred` + channel upload role |
| 5 | Multiple independent static callers | **Falsified** — sole `FUN_00731130` (2 sites) |
| 6 | Returns void | **Falsified** — EAX status / −1 fail path |
| 7 | Material always stride 0x10 | **Falsified** — 0x20 default when child null/flag0 |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| stdcall host* + ch + RET 8 | **High** | Wrong ABI |
| Channel offsets +4/+0xc/+0x24/+0x34 | **High** | Wrong layout |
| 0x152 / 0x800 / 0x24 / 0x44×3 | **High** | Wrong GPU path |
| gfxDeviceVB plate (unlock only) | **High** | Mis-own class |
| Product English | **Low** | Naming only |
| Unowned helpers | **Open** | Incomplete port |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes + xrefs

- Body range Ghidra `00730b50`–`00731123`; pad CC then `FUN_00731130`.
- Epilogue `81 C4 24 01 00 00 C2 08 00` (add esp 0x124; ret 8).
- Xrefs: `00731299`, `007313ee` only — both in dual-channel init.
- Material slot math `+0x34+ch*8` matches W36-J host+0x34 / +0x3c.

---

## 4. Surviving contract for AutoCore

```
// Port as stdcall per-channel geom upload (not thiscall, not bare gfxDeviceVB API):
uint32_t UploadChannelGeom(void *host /*0x44*/, int ch /*0|1*/) {
  // build 3 local streams; set host counts; VB 0x152 Lock 0x800;
  // copy verts; unlock; stride from mat child; bind host+0x24+ch*8
  // return status (0xFFFFFFFF on VB create fail)
}
// Pair with W36-J dual-channel init and W35-E slot5 new(0x44).
// Do not invent product host class English.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, channel layout, VB/IB constants, sole caller, plate role. Residual product English + helpers → **accept-with-gaps**.
