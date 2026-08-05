# Function record: CVOGObject_SetGfxBodyLink_Mode1AndTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058e370` |
| **Canonical name** | `CVOGObject_SetGfxBodyLink_Mode1AndTarget` (**Inferred**) |
| **Ghidra symbol** | `FUN_0058e370` |
| **Address** | `0x0058e370` |
| **Body** | `0x0058e370`–`0x0058e398` (40 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client CVOG object / gfxBody link packet |
| **Completion status** | **Sealed** — W20-M dual A/B 2026-07-29 |
| **Bit-for-bit / runtime / diff** | Open (deferred) |
| **Verdict** | **accept** |

## Alias

- `FUN_0058e370`
- `Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Cli_0058e370` (**parent-seed noise**)

## Purpose

If `this->gfxBody` (`+0x914`) and `gfxBody->linkPacket` (`+0x78`) are non-null, set packet **mode = 1** and **packet+4 = target**. Used when a manager broadcasts a selected target entity onto list members' gfx link packets.

## Signature

```c
// __thiscall; ret 4
void CVOGObject_SetGfxBodyLink_Mode1AndTarget(void *self, void *target);
```

## Offsets

| Path | Meaning | Evidence |
|---|---|---|
| `self+0x914` | gfxBody* | creator `0x0058f780` + string `gfxBody` |
| `gfxBody+0x78` | link packet* | create assigns `operator_new(0xC)` packet |
| `packet+0` | mode byte | this writes `1`; create/teardown write `9` |
| `packet+4` | associated ptr | this writes target; create writes self |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0058e370_FUN_0058e370.md`
- Annotated: `docs/reconstruction/raw/aa_0058e370_FUN_0058e370.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGObject_SetGfxBodyLink_Mode1AndTarget.cpp`
- Alias clean: `docs/reconstruction/reconstructed-exact/FUN_0058e370.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_0058e370_CVOGObject_SetGfxBodyLink_Mode1AndTarget.md`
- Review B: `docs/reconstruction/reviews/B_aa_0058e370_CVOGObject_SetGfxBodyLink_Mode1AndTarget.md`

## Callers / callees

**Callees:** none (leaf stores only).

**Callers (1):** `FUN_004b73c0` @ `0x004b7408` — after caching target/orientation, walks `this+0x204` list; for each node with non-null value, calls this unit with the target object as arg (thiscall this = list value object).

## Confidence

| Claim | Level |
|---|---|
| CF: dual null gate + mode1 + store target | **High** |
| ABI `__thiscall` `ret 4` | **High** (byte seal) |
| `+0x914` = gfxBody | **High** (string + creator) |
| Mode enum product names | **Open** |
| Target semantic beyond pointer | **Medium** (caller param_2 entity) |
