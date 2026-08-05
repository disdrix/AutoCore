# Function record: Object_ResolveTargetViaReaction_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00578270` |
| **Canonical name** | `Object_ResolveTargetViaReaction_Inferred` |
| **Ghidra** | `FUN_00578270` |
| **Address** | `0x00578270`–`0x00578298` (**40 B**) |
| **Module** | `autoassault.exe` base `0x400000` |
| **System** | object / reaction / targeting |
| **Wave** | W28-F dual seal 2026-07-29 |
| **Verdict** | **accept-with-gaps** |

## Signature

```c
void *__fastcall Object_ResolveTargetViaReaction_Inferred(void *host /*ECX*/);
```

## Sealed behavior

1. `reaction = *(*(host + 0x688) + 0xe4e8)`.
2. `flag = *(uint8_t*)(host + 0x660)`; `id0 = *(uint32_t*)(host + 0x658)`; `id1 = *(host + 0x65c)`.
3. `return CVOGReaction_ResolveObjectTarget(reaction, flag, id0, id1)`.

## Port notes

- **Must return** the callee pointer — do not model as void.
- Host ECX is the object owning the stored target ids, not the reaction object.
- Consumers (e.g. W27-F `00626890`) may treat return as manager and call `vfunc+0x210(0)` for player — preserve that chain outside this unit.
- Do not invent TFID English without dual of `004e3260`.

## Gaps

- Product class of host / return / reaction.
- Exact id-pair schema at `+0x658/+0x65c`.
- Flag `+0x660` product meaning.
- Nested dual of `CVOGReaction_ResolveObjectTarget`.

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00578270_FUN_00578270.md` |
| Annotated | `docs/reconstruction/raw/aa_00578270_FUN_00578270.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_ResolveTargetViaReaction_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00578270.cpp` |
| A/B | `reviews/A_aa_00578270_Object_ResolveTargetViaReaction_Inferred.md`, `B_…` |
